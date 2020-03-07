#include<iostream>
#include<vector>
using namespace std;

int w, h;
int m[50][50];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c) {
    m[r][c] = -1;
    for (int i = 0 ; i < 8; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if (0 <= nr && nr < h && 0 <= nc && nc < w && m[nr][nc] > 0)
            dfs(nr, nc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> m[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w ; j++) {
                if (m[i][j] > 0){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}