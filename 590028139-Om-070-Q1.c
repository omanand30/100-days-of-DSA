#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    vector<int> dist(n, 1e9); 
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            if (dist[edge.u] != 1e9 && 
                dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for (auto edge : edges) {
        if (dist[edge.u] != 1e9 && 
            dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }

    cout << "Shortest distances from source:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == 1e9)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}