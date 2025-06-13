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
    grafo[1] = {{0, 8}, {2, 2}};
    grafo[2] = {{0, 5}, {3, 1}};
    grafo[3] = {{0, 2}};
    int inicio = 0;
    vector<int> dist(n, INF);
    dist[inicio] = 0;
    // Cola de prioridad para seleccionar el nodo con la distancia minima
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, inicio});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (const auto& neighbor : grafo[u])
        {
            int v = neighbor.first;
            int peso = neighbor.second;
            if (dist[u] != INF && dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    cout << endl;
    //Podemos decir que su complejidad es de O((V+E)*log V),donde V es el numero de nodos y E el numero de aristas
}
