#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> g[100001];
bool visited[100001];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++) {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }


    vector<int> q;
    queue<int> buffer;

    int next, index = 0;
    cin >> next;
    if (next != 1) {
        cout << 0 << '\n';
        return 0;
    } else {
        q.push_back(1);
        visited[1] = true;
        buffer.push(1);
    }

    int node;
    while(!q.empty()) {
        bool found = false;

        for (int i = 0 ; i < buffer.front() ; i++) {
            if (next == q[i]) { 
                found = true; 
                node = *(q.begin() + i);
                q.erase(q.begin() + i);
                buffer.front()--;
                index++;
                if (buffer.front()==0) buffer.pop();
                break;
            }
        }

        
        if (!found) { cout << 0 << '\n'; return 0; }
        // cout << "pop " << node << '\n';

        int cnt = 0;
        for (int neigh : g[node]) {
            if (!visited[neigh]){
                q.push_back(neigh);
                visited[neigh] = true;
                cnt++;
            }
        }
        if (cnt!=0)
        buffer.push(cnt);
        // cout << "push " << cnt << '\n';
        
        if (index!=n)
            cin >> next;
    }

    cout << 1 << '\n';

    return 0;
    
}