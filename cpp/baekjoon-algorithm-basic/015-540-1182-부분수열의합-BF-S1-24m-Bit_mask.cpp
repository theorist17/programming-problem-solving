#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, a[20];
    cin >> n >> s;

    for (int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    int cnt = 0, sum;
    for (int i = 1 ; i < (1 << n) ; i++){
        sum = 0;
        for (int j = 0 ; j  < n ; j++) 
            if ((i & (1 << j)) != 0) 
                sum += a[j];
        if (sum == s)
            cnt++;
    }
    cout << cnt << '\n';
    
    return 0;
}