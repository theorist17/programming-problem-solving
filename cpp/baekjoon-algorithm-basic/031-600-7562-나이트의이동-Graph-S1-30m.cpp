#include<iostream>
#include<queue>
#include<string>
using namespace std;

int tc, l, r, c, n, m;
bool visited[300][300];

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    while(tc--){
        cin >> l >> r >> c >> n >> m;
        
        for (int i = 0 ; i < l ; i++)
            for (int j = 0 ; j < l ; j++)
                visited[i][j] = false;
        queue<pair<int, int> > q;
        queue<int> d;
        q.push(make_pair(r, c));
        d.push(0);
        visited[r][c] = true;

        while(!q.empty()){
            r = q.front().first, c = q.front().second;
            q.pop();
            int depth = d.front();
            d.pop();

            if (r == n && c == m)
                cout <<  depth << "\n";
            
            for (int i = 0 ; i < 8; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if (0 <= nr && nr < l && 0 <= nc && nc < l && !visited[nr][nc]){
                    q.push(make_pair(nr, nc));
                    d.push(depth + 1);
                    visited[nr][nc] = true;
                }
            }
        }
    }


    return 0;
}