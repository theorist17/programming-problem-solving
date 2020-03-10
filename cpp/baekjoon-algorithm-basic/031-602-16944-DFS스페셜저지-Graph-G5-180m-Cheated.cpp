#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> adj[100001];
vector<int> dfs_order;
bool visited[100001];

bool dfs(int node) {
    if (visited[node]) return false;
    visited[node] = true;
    dfs_order.push_back(node);
    bool ret = true;
    for(int i = 0 ; i < adj[node].size() ; i++) {
        if (!visited[adj[node][i]]) {
            ret &= dfs(adj[node][i]);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    vector<int> b(n+1);
    vector<int> order(n+1);
    for (int i = 1 ; i <= n ; i++){
        cin >> b[i];
        order[b[i]] = i;
    }

    int node = order[1];
    if (node != 1) {cout << 0 << '\n'; return 0; }

    for (int i = 1 ; i <= n ; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }

    dfs(1);

    b.erase(b.begin());
    if (b == dfs_order) 
        cout << 1 << '\n';
    else 
        cout << 0 << '\n';
    
    return 0;
}