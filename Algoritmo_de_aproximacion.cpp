#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
const int numero_ciudad = 5;
// Matriz de distancias entre ciudades (ejemplo)
vector<vector<int>> distancias =
{
    {0, 10, 15, 20, 25},
    {10, 0, 35, 30, 12},
    {15, 35, 0, 18, 22},
    {20, 30, 18, 0, 16},
    {25, 12, 22, 16, 0}
};
int main()
{
    vector<bool> visitado(numero_ciudad, false);
    vector<int> viaje;
    int inicio_ciudad = 0; // Empezamos desde la ciudad 0
    // Iniciar el recorrido desde la ciudad inicial
    viaje.push_back(inicio_ciudad);
    visitado[inicio_ciudad] = true;
    // Construir el recorrido utilizando el vecino más cercano
    for (int i = 1; i < numero_ciudad; ++i)
    {
        int concurrente_ciudad = viaje.back();
        int vecino_cercano = -1;
        int minima_distancia = INT_MAX;
        // Encontrar el vecino más cercano no visitado
        for (int j = 0; j < numero_ciudad; ++j)
        {
            if (!visitado[j] && j != concurrente_ciudad && distancias[concurrente_ciudad][j] < minima_distancia) {
                minima_distancia = distancias[concurrente_ciudad][j];
                vecino_cercano = j;
            }
        }
        // Añadir el vecino más cercano al recorrido
        viaje.push_back(vecino_cercano);
        visitado[vecino_cercano] = true;
    }
    // Calcular la longitud del recorrido encontrado
    int viajetamb = 0;
    for (int i = 0; i < numero_ciudad - 1; ++i)
        viajetamb += distancias[viaje[i]][viaje[i + 1]];
    viajetamb += distancias[viaje[numero_ciudad - 1]][viaje[0]]; // Regresar al punto inicial
    // Imprimir el recorrido encontrado y su longitud
    cout << "Recorrido encontrado: ";
    for (int ciudad : viaje)
        cout << ciudad << " ";
    cout << endl;
    cout << "Longitud del recorrido: " << viajetamb << endl;
    //La complejidad de este algoritmo es de O(n^2)
}

