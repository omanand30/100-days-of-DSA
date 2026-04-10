#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
  
        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}