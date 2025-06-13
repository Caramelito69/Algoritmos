#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
int main()
{
    int n = 4;
    vector<vector<pair<int, int>>> grafo(n);
    grafo[0] = {{1, 3}, {3, 7}};
    grafo[1] = {{0, 3}, {2, 2}};
    grafo[2] = {{1, 2}, {3, 1}};
    grafo[3] = {{0, 7}, {2, 1}};
    vector<int> llave(n, INF); // Valores clave usados para elegir arista de menor peso
    vector<int> nodo_padre(n, -1); // Array para almacenar el MST
    vector<bool> buscar(n, false); // Para rastrear los nodos incluidos en el MST
    int inicio = 0; // Nodo de inicio
    llave[inicio] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, inicio});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        buscar[u] = true;
        for (const auto& nodo_vecino : grafo[u])
        {
            int v = nodo_vecino.first;
            int peso = nodo_vecino.second;
            if (!buscar[v] && peso < llave[v])
            {
                llave[v] = peso;
                pq.push({llave[v], v});
                nodo_padre[v] = u;
            }
        }
    }
    cout << "Nodos \Peso\n";
    for (int i = 1; i < n; ++i)
        cout << nodo_padre[i] << " - " << i << " \t" << llave[i] << "\n";
    //La complejidad es O(E log V)
}

