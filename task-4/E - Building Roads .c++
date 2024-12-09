#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> components;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            components.push_back(i);
            dfs(i);
        }
    }

    int k = components.size() - 1;
    cout << k << endl;
    for (int i = 1; i < components.size(); ++i) {
        cout << components[i - 1] << " " << components[i] << endl;
    }

    return 0;
}
