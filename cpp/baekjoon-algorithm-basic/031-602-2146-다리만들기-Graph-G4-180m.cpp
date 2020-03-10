#include<iostream>
#include<queue>
using namespace std;

int n;
int m[100][100];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool visited[100][100];

void dfs(int r, int c, int cnt) {
    m[r][c] = cnt;

    for (int i = 0 ; i < 4; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if(0 <= nr && nr < n && 0 <= nc && nc < n && m[nr][nc]==0)
            dfs(r+dr[i], c+dc[i], cnt);
    
            // for (int i = 0 ; i < n; i++){
            //     for (int j = 0 ; j < n; j++) {
            //         cout << m[i][j] << " " ;
            //     } cout << "\n";
            // }
            // cout << "\n";
}
}

int main() {
    cin >> n;

    for (int i = 0 ; i < n ; i++) 
        for (int j = 0; j < n ; j++) {
            cin >> m[i][j];
            m[i][j]--;
        }

    int cnt = 1;
    for (int i = 0 ; i < n; i++)
        for (int j = 0 ; j < n; j++)
            if(m[i][j]==0)
                dfs(i, j, cnt++);

    for (int i = 0 ; i < n; i++)
        for (int j = 0 ; j < n; j++)
            if(m[i][j] == -1)
                m[i][j] = 0;
            
    int ans = 99999;
    for (int k = 1 ; k <= cnt ; k++) {
        queue<pair<pair<int, int>, pair<int, int> > > q;
        for (int i = 0 ; i < n; i++)
            for (int j = 0 ; j < n; j++){
                if(m[i][j] == k)
                    q.push(make_pair(make_pair(i, j), make_pair(m[i][j], 0)));
                visited[i][j] = false;
            }

        bool found = false;
        while(!q.empty()){
            int r = q.front().first.first, c = q.front().first.second;
            int a = q.front().second.second;
            int num = q.front().second.first; 
            q.pop();

            for (int i = 0; i < 4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(0 <= nr && nr < n && 0 <= nc && nc < n){
                    if (m[nr][nc] != 0 && m[nr][nc] != k) {
                        if (ans > a) ans = a;
                        found = true;
                        break;
                    } else if (!visited[nr][nc]) {
                        q.push(make_pair(make_pair(nr, nc), make_pair(num, a + 1)));
                        visited[nr][nc] = true; 
                    }
                }
            }

            if (found) break;
        }
    }

    cout << ans << "\n";

    return 0;
}