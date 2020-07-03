#include<iostream>
#include<queue>
using namespace std;

int n;
bool visited[1001][1001];
int d[1001][1001];

int main() {
    cin >> n;

    queue<int> screen, clipboard;
    screen.push(1);
    clipboard.push(0);
    visited[1][0] = true;
    d[1][0] = 0;

    while(!screen.empty()){
        int s = screen.front(), c = clipboard.front();
        screen.pop(); clipboard.pop();

        if (s==n) {
            cout << d[s][c] << '\n';
            return 0;
        }

        // copy
        if (!visited[s][s]) {
            screen.push(s); clipboard.push(s);
            visited[s][s] = true;
            d[s][s] = d[s][c] + 1;
        }

        // paste
        if (s + c <= 1000 && !visited[s+c][c]) {
            screen.push(s+c); clipboard.push(c);
            visited[s+c][c] = true;
            d[s+c][c] = d[s][c] + 1;
        }

        // delete
        if (2 < s && !visited[s-1][c]) {
            screen.push(s-1); clipboard.push(c);
            visited[s-1][c] = true;
            d[s-1][c] = d[s][c] + 1;
        }
    } 
    return 0;
}