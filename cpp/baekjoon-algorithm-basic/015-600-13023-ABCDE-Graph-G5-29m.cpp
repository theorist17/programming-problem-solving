#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    int here, there;
    for (int i = 0; i < m; i++) { 
        cin >> here >> there;
        g[here].push_back(there);
        g[there].push_back(here);
    }

    int abcde = 0;

    queue<pair<int, int> > q;
    vector<int> visited(n, 0);
    for (int i = 0 ; i < n; i++){
        if (!visited[i])
            q.push(make_pair(i, 1));
        while(!q.empty()) {
            int here = q.front().first;
            int depth = q.front().second;
            cout << "visiting " << here << " " << depth << "\n";
            q.pop();
            if (abcde < depth)
                abcde = depth;
            
            for (int j = 0; j < g[here].size(); j++){
                if (!visited[g[here][j]]){
                    visited[here] = true;
                    q.push(make_pair(g[here][j], depth + 1));
                }
            }
        }
    }

    if (abcde >= 5)
        cout << true << '\n';
    else
        cout << false << '\n';
    
    return 0;
}