#include<bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
void dijkstra(int n, const vector<vector<pair<int, int>>>& graph, int start, vector<int>& dist)
{
    dist.assign(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u])
            continue;
        for (const auto& edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    // Representación de un grafo no dirigido
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[0].push_back({2, 3});
    adj[2].push_back({0, 3});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});
    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});
    adj[2].push_back({3, 8});
    adj[3].push_back({2, 8});
    adj[2].push_back({4, 2});
    adj[4].push_back({2, 2});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 7});
    int start_node = 0;
    vector<int> shortest_distances(V);
    dijkstra(V, adj, start_node, shortest_distances);
    for (int i = 0; i < V; ++i)
        cout << "Nodo " << i << ": " << (shortest_distances[i] == INF ? -1 : shortest_distances[i]) << endl;
}
