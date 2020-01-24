#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    int D[100001][3];
    D[1][0] = 1; D[1][1] = 1; D[1][2] = 1;

    for (int i = 2 ; i <= n ; i++)
    {
        D[i][0] = D[i-1][0]; D[i][0] %= 9901;
        D[i][0] += D[i-1][1]; D[i][0] %= 9901;
        D[i][0] += D[i-1][2]; D[i][0] %= 9901;
        D[i][1] = D[i-1][0]; D[i][1] %= 9901;
        D[i][1] += D[i-1][2]; D[i][1] %= 9901;
        D[i][2] = D[i-1][0]; D[i][2] %= 9901;
        D[i][2] += D[i-1][1]; D[i][2] %= 9901;
    }

    int ans = D[n][0]; ans %= 9901;
    ans += D[n][1]; ans %= 9901;
    ans += D[n][2]; ans %= 9901;
    cout << ans << '\n';

	return 0;
}