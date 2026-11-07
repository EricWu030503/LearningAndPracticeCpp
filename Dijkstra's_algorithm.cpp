#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity for unvisited nodes

// Function to perform Dijkstra's algorithm
void dijkstra(int source, int n, const vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& prev) {
    // Priority queue to store nodes with their distances (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Initialize distances and previous nodes
    dist.assign(n, INF);
    prev.assign(n, -1);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If the distance is outdated, skip
        if (d > dist[u]) continue;

        // Process each neighbor of node `u`
        for (const auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// Function to reconstruct the shortest path from source to a target
vector<int> reconstructPath(int target, const vector<int>& prev) {
    vector<int> path;
    for (int at = target; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

// Main function
int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Undirected graph
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> dist, prev;
    dijkstra(source, n, adj, dist, prev);

    cout << "\nShortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << endl;
        }
    }

    cout << "\nShortest paths from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": ";
            vector<int> path = reconstructPath(i, prev);
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
