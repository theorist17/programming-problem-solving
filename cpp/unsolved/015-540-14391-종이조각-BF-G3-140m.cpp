#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n, m;
int a[4][4];
int check[4][4] = {0, };
int ans = 0;
void cut(int score, int k) {
    int r = -1, c = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!check[i][j]){
                r = i, c = j; 
                break;
            }
        }
        if (r != -1 || c != -1)
            break;
    }
    
    if (r == -1 && c == -1) {
        if (ans < score){
            ans = max(ans, score);            
        }
        return;
    }

    // vertical 
    int temp = 0;
    for (int i = r; i < n; i++){
        check[i][c] = k;
        temp = temp * 10 + a[i][c];
        cut(score + temp, k + 1);
    }
    for (int i = r ; i < n; i++)
        check[i][c] = 0;
    
    // horizontal
    temp = 0;
    for (int j = c ; j < m; j++){
        check[r][j] = k;
        temp = temp * 10 + a[r][j];
        cut(score + temp, k + 1);
    }
    for (int j = c; j < m; j++)
        check[r][j] = 0;
}


int main() {
    cin >> n >> m; cin.ignore();

    int i = 0;
    while(i < n){
        string line;
        getline(cin, line);
        for (int j = 0; j < m; j++)
            a[i][j] = line[j] - '0';
        i++;
    }
    
    cut(0, 1);
    cout << ans << "\n";
    

    return 0;
}