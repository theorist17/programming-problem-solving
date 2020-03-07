#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, m, cnt = 0, tar = 0;
int a[1000][1000];
bool visited[1000][1000];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool ok() {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        } 
    }

    queue<pair<int, int> > q;
    queue<int> d;
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] != -1)
                tar++;
            if (a[i][j] == 1){
                q.push(make_pair(i, j));
                d.push(0);
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()){
        int r = q.front().first, c = q.front().second; q.pop();
        int depth = d.front(); d.pop();
        a[r][c] = 1;
        cnt++;
    
        if (cnt == tar){
            cout << depth << "\n";
            return 0;
        }
        
        for (int i = 0 ; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && a[nr][nc] == 0 && !visited[nr][nc]){
                q.push(make_pair(nr, nc));
                d.push(depth + 1);
                visited[nr][nc] = true;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}