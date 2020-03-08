#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> g[100001];
bool visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }


    queue<int> q;

    int next;
    cin >> next;
    if (next != 1) {
        cout << 0 << '\n';
        return 0;
    } else {
        q.push(1);
        visited[1] = true;
    }

    int i;
    for ( i = 1 ; i < n ; i++) {
        cin >> next;
        
        int node = q.front(); q.pop();

        bool found = false;
        for (int neigh : g[node]) {
            if (next == neigh && !visited[next]) {
                found = true;
                q.push(next);
                visited[next] = true;
            }
        }

        if (!found){
            cout << 0 << '\n';
            return 0;
        }
    }

    if (i != n - 1)
        cout << 0 << '\n';
    else 
        cout << 1 << '\n';

    return 0;
    
}