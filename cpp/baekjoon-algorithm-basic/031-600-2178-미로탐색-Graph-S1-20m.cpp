#include<iostream>
#include<queue>
#include<string>
using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin.ignore();
    for (int i = 0 ; i < n ; i++){
        string line;
        getline(cin, line);
        for (int j = 0 ; j < line.length() ; j++) 
            a[i][j] = line[j] - '0';
    }

    queue<pair<int, int> > q;
    queue<int> d;
    q.push(make_pair(0, 0));
    d.push(1);
    visited[0][0] = true;

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        int depth = d.front();
        d.pop();

        if (r == n - 1 && c == m - 1)
            cout << depth << "\n";
        
        for (int i = 0 ; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && a[nr][nc] == 1 && !visited[nr][nc]){
                q.push(make_pair(nr, nc));
                d.push(depth + 1);
                visited[nr][nc] = true;
            }
        }
    }


    return 0;
}