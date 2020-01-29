#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
int a[10];
int s[10][10];

void allNumber(int idx) {
    if (idx == n) {
        for (int i = 0 ; i < n ; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }

    if (s[idx][idx] == '0'){
        a[idx] = 0;
        allNumber(idx + 1);
    } else {
        int sign = s[idx][idx] == '+'? 1 : -1;
        for (int i = 1; i <= 10; i++) {
            a[idx] = i * sign;
            allNumber(idx + 1);
        }
    }
    
    for (int i = -10; i <= 10; i++) {
        a[idx] = i;
        allNumber(idx + 1);
    }
}

int main() {;
    cin >> n; cin.ignore();
    for (int i = 0 ; i < n; i++)
        a[i] = -1;
    for (int i = 0 ; i < n; i++)
        for (int j = 0; j < n; j++) 
            s[i][j] = 0;
    for (int i = 0 ; i < n; i++)
        for (int j = i ; j < n; j++) 
            s[i][j] = cin.get();
    for (int i = 0 ; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << s[i][j];
        cout << "\n";
    }
    
    allNumber(0);
    

    return 0;
}