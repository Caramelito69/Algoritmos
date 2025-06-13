#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const int numero_ciudades = 5;
const int numero_ant = 3;
const double ALPHA = 1.0;   // Influencia de la feromona
const double BETA = 2.0;    // Influencia de la distancia
const double EVAPORACION = 0.5; // Tasa de evaporación de la feromona
// Matriz de distancias entre ciudades (ejemplo)
vector<vector<double>> distancias =
{
    {0, 10, 15, 20, 25},
    {10, 0, 35, 30, 12},
    {15, 35, 0, 18, 22},
    {20, 30, 18, 0, 16},
    {25, 12, 22, 16, 0}
};
// Matriz de feromonas entre ciudades (inicializada con un valor pequeño)
vector<vector<double>> feromonas(numero_ciudades, vector<double>(numero_ciudades, 0.1));
// Función para calcular la longitud de un recorrido
double calculartam(const vector<int>& tour)
{
    double tam = 0.0;
    for (int i = 0; i < tour.size() - 1; ++i)
        tam += distancias[tour[i]][tour[i + 1]];
    tam += distancias[tour.back()][tour[0]]; // Cerrar el ciclo
    return tam;
}
int main()
{
    srand(time(NULL)); // Inicialización de la semilla aleatoria
    // Inicialización de las hormigas (cada una comienza en una ciudad diferente)
    vector<vector<int>> viajes(numero_ant, vector<int>(numero_ciudades));
    for (int ant = 0; ant < numero_ant; ++ant) {
        vector<bool> visitado(numero_ciudades, false);
        int inicio_ciudad = rand() % numero_ciudades;
        int concurrente_ciudad = inicio_ciudad;
        visitado[inicio_ciudad] = true;
        viajes[ant][0] = inicio_ciudad;
        // Construcción del recorrido de la hormiga
        for (int i = 1; i < numero_ciudades; ++i) {
            double total = 0.0;
            vector<double> probabilidad(numero_ciudades, 0.0);
            // Calcular la suma del numerador
            for (int j = 0; j < numero_ciudades; ++j)
            {
                if (!visitado[j])
                {
                    double numerador = pow(feromonas[concurrente_ciudad][j], ALPHA) * pow(1.0 / distancias[concurrente_ciudad][j], BETA);
                    probabilidad[j] = numerador;
                    total += numerador;
                }
            }
            // Normalizar las probabilidades
            double randValue = (double)rand() / RAND_MAX; // Valor aleatorio entre 0 y 1
            double cumulativeProbability = 0.0;
            int nextCity = -1;
            for (int j = 0; j < numero_ciudades; ++j)
            {
                if (!visitado[j])
                {
                    probabilidad[j] /= total;
                    cumulativeProbability += probabilidad[j];
                    if (randValue <= cumulativeProbability)
                    {
                        nextCity = j;
                        break;
                    }
                }
            }
            // Marcar la siguiente ciudad como visitada
            visitado[nextCity] = true;
            viajes[ant][i] = nextCity;
            concurrente_ciudad = nextCity;
        }
    }

    // Actualización de las feromonas después de la primera iteración
    // Evaporación de feromonas
    for (int i = 0; i < numero_ciudades; ++i)
        for (int j = 0; j < numero_ciudades; ++j)
            feromonas[i][j] *= (1.0 - EVAPORACION);
    // Deposito de feromonas por cada hormiga
    for (const auto& tour : viajes)
    {
        double tourLength = calculartam(tour);
        for (int i = 0; i < tour.size() - 1; ++i)
        {
            int ciudad1 = tour[i];
            int ciudad2 = tour[i + 1];
            feromonas[ciudad1][ciudad2] += 1.0 / tourLength; // Incrementar feromona proporcionalmente a la longitud inversa del recorrido
            feromonas[ciudad2][ciudad1] += 1.0 / tourLength; // Asegurar simetría en la matriz de feromonas
        }
        // Depositar feromona para cerrar el ciclo
        int lastCity = tour.back();
        int firstCity = tour.front();
        feromonas[lastCity][firstCity] += 1.0 / tourLength;
        feromonas[firstCity][lastCity] += 1.0 / tourLength;
    }
    // Encontrar la mejor solución entre las hormigas
    int grantam = 0;
    double shortestTourLength = calculartam(viajes[0]);
    for (int ant = 1; ant < numero_ant; ++ant)
    {
        double tourLength = calculartam(viajes[ant]);
        if (tourLength < shortestTourLength)
        {
            shortestTourLength = tourLength;
            grantam = ant;
        }
    }
    // Imprimir la mejor solución encontrada
    cout << "Mejor recorrido encontrado: ";
    for (int ciudad : viajes[grantam])
        cout << ciudad << " ";
    cout << endl;
    cout << "Longitud del recorrido: " << shortestTourLength << endl;
    //Su complejidad es de O(n^2)
}
