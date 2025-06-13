#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int INF = INT_MAX;
int main()
{
    vector<vector<int>> grafo = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 30, 12},
        {15, 35, 0, 18, 22},
        {20, 30, 18, 0, 16},
        {25, 12, 22, 16, 0}
    };
    int n = grafo.size();
    vector<bool> visitado(n, false);
    vector<int> padre;
    int inicio = 0;
    padre.push_back(inicio);
    visitado[inicio] = true;
    for (int i = 0; i < n - 1; ++i)
    {
        int c = padre.back();
        int nodovecino = -1;
        int minima_distancia = INF;
        for (int j = 0; j < n; ++j)
        {
            if (!visitado[j] && grafo[c][j] < minima_distancia)
            {
                minima_distancia = grafo[c][j];
                nodovecino = j;
            }
        }
        padre.push_back(nodovecino);
        visitado[nodovecino] = true;
    }
    padre.push_back(inicio);
    cout << "Camino del recorrido del TSP:\n";
    for (int nodo : padre)
        cout << nodo << " ";
    cout << endl;
    //Su complejidad es de O(n^2)
}
