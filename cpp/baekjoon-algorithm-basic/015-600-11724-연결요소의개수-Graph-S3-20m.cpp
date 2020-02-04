#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> g[1001];
bool check[1001] = {false, };
int component = 0;

void dfs(int node) {
    check[node] = true;
    for(int i = 0 ; i < g[node].size(); i++){
        int next = g[node][i];
        if(!check[next])
            dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    // for (int i = 1; i <= n ; i++) {
    //     for (int j = 0 ; j < g[i].size();  j++)
    //         cout << g[i][j] << " ";
    //     cout << '\n';
    // }

    for (int i = 1 ; i <= n ; i++) {
        if(check[i]) continue;
        dfs(i);
        component++;
    }

    cout << component << "\n";


    return 0;
}