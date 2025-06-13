#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Estructura para representar una arista
struct Edge
{
    int u, v, peso;
};
// Comparador para ordenar las aristas por peso
bool compare(Edge a, Edge b)
{
    return a.peso < b.peso;
}
// Estructuras para conjuntos disjuntos (Union-Find)
int find(int u, vector<int>& parent)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}
void merge(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else
        {
            parent[rootV] = rootU;
            ++rank[rootU];
        }
    }
}
int main()
{
    int n = 4;
    vector<Edge> edges = { {0, 1, 3}, {0, 3, 7}, {1, 2, 2}, {2, 3, 1} };
    // Ordenar las aristas por peso
    sort(edges.begin(), edges.end(), compare);
    // Inicialización de conjuntos disjuntos
    vector<int> padre(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i)
        padre[i] = i;
    vector<Edge> mst;
    for (const auto& edge : edges)
        if (find(edge.u, padre) != find(edge.v, padre))
        {
            mst.push_back(edge);
            merge(edge.u, edge.v, padre, rank);
        }
    // Imprimir el arbol de expansion minima(MST)
    cout << "Nodos \tPeso\n";
    for (const auto& edge : mst)
        cout << edge.u << " - " << edge.v << " \t" << edge.peso << "\n";
    //Su complejidad es de O(E log E)
}

