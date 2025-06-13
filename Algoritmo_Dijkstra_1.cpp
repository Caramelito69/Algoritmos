#include <bits/stdc++.h>
#define INI cin.ti(0)->sync_with_stdio(0);
using namespace std;
void dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start)
{
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : graph[u])
        {
            int v=edge.first,w=edge.second;
            if (dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pq.emplace(dist[v],v);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << "Nodo " << i << ": " << (dist[i] == numeric_limits<int>::max() ? -1 : dist[i]) << endl;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);
    graph[0] = {{1, 10}, {2, 3}};
    graph[1] = {{2, 1}, {3, 2}};
    graph[2] = {{1, 4}, {3, 8}, {4, 2}};
    graph[3] = {{4, 7}};
    graph[4] = {{3, 9}};
    dijkstra(V, graph, 0);
}
