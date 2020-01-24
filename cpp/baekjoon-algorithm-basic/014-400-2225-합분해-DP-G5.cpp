#include<iostream>
#include<vector>
using namespace std;

# https://www.acmicpc.net/source/share/f1f0f435bcf14e2b8c9d8d6d576eb496

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int> > D(n+1, vector<int>(k+1));
    
    for (int i = 1 ; i <= n ; i++)
        D[i][1] = 1;
    for (int j = 1 ; j <= k ; j++)
        D[1][j] = j;
    for (int i = 2 ; i <= n ; i++)
        for (int j = 2; j <= k ; j++)
            D[i][j] = (D[i-1][j] + D[i][j-1]) % 1000000000;
    
    cout << D[n][k] << '\n';
    
	return 0;
}