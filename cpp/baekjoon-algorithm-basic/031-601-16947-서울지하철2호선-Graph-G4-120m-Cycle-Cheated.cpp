#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> g[3001];
int depth[3001];
int check[3001];

int dfs(int node, int prev) {
    // find cycle
    // -2 cycle found, but the node is not in the cycle
    // -1 cycle not found yet
    // 0 ~ n-1 cycle found with its initial node index

    if (check[node]==1) return node;
    check[node] = 1;

    for (int next : g[node]) {
        if (next == prev) continue;
        int ret = dfs(next, node);
        if (ret == -2) return -2;
        if (ret >= 0) {
            check[node] = 2;
            if (ret == node) return -2; 
            else return ret;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n ;i++){
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    dfs(1, -1);


    for (int i = 1 ; i <= n ; i++){
        cout << check[i] << " ";
    }
    cout << "\n";

    queue<int> q;
    for (int i = 1 ; i <= n ; i++){
        if(check[i]==2){
            q.push(i);
            depth[i] = 0;
        } else {
            depth[i] = -1;
        }
    }

    while(!q.empty()) {
        int node = q.front(); q.pop();
        
        for (int next : g[node]){
            if (depth[next] == -1) {
                q.push(next);
                depth[next] = depth[node] + 1;
            }
        }
    }

    for (int i = 1 ; i <= n ; i++){
        cout << depth[i] << " ";
    }
    cout << "\n";
    return 0;
}