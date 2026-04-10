#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
  
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int node = it.second;

        if (d > dist[node]) continue;

        for (auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;

    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});


    int src = 0;

    vector<int> result = dijkstra(n, adj, src);

    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " = " << result[i] << endl;
    }

    return 0;
}