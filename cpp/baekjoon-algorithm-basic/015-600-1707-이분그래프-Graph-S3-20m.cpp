#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> g[20001];
int check[200001] = {0, };
int component = 0;

void dfs(int node, int set) {
    check[node] = set;
    cout << "visiting " << node << "\n";
    for(int i = 0 ; i < g[node].size(); i++){
        int next = g[node][i];
        if(check[next] != 0)
            dfs(next, 3 - set);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    while(k--){

        cin >> n >> m;

        for (int i = 0 ; i < n; i++) {
            vector<int> t;
            g[i].swap(t);
            check[i] = 0;
        }
        
        for (int i = 0 ; i < m ; i++) {
            int from, to;
            cin >> from >> to;
            g[from].push_back(to);
            g[to].push_back(from);
        }

        dfs(1, 1);
    }

    cout << component << "\n";


    return 0;
}