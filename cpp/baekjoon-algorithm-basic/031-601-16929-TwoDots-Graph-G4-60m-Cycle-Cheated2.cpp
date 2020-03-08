#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, m;
char a[50][50];
bool visited[50][50];
int dist[50][50];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool dfs(int r, int c, int d){
    if (visited[r][c])
        return d - dist[r][c] >= 4;
    visited[r][c] = true;
    dist[r][c] = d;
    
    for (int i = 0 ; i < 4; i++){
        int nr = r + dr[i], nc = c + dc[i];
        if (0 <= nr && nr < n && 0 <= nc && nc < m && a[r][c] == a[nr][nc]){
            if(dfs(nr, nc, d + 1))
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin.ignore();
    for (int i = 0 ; i < n ; i++){
        string line;
        getline(cin, line);
        for (int j = 0 ; j < line.length() ; j++)
            a[i][j] = line[j];
    }

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m ; j++){
            if(!visited[i][j]){
                if(dfs(i, j, 0)){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}