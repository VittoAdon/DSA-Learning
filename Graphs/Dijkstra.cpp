#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph
{
    int numVertices;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int n)
    {
        numVertices = n;
        adj.resize(n);
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    vector<int> dijkstra(int src)
    {
        vector<int> dist(numVertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto edge : adj[u])
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

        return dist;
    }
};

int main()
{
    int n = 5;
    Graph g(n);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    int startNode = 0;
    vector<int> shortestDistances = g.dijkstra(startNode);

    for (int i = 0; i < n; ++i)
    {
        cout << "Node " << i << " -> " << shortestDistances[i] << "\n";
    }

    return 0;
}