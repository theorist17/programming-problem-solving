#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<vector<int> > D(1001, vector<int>(10, 0));
    for (int i = 0 ; i < 10; i++)
        D[1][i] = 1;

    for (int i = 2 ; i <= n ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                D[i][j] += D[i-1][k]; D[i][j] %= 10007;
            }
        }
    }

    int ans = 0;
    for (int j = 0 ; j < 10; j++)
    {
        ans += D[n][j]; ans %= 10007;
    }
    
    cout << ans << '\n';

	return 0;
}