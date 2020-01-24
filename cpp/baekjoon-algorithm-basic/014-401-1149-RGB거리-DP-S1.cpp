#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<vector<int > > D(n+1, vector<int>(4));

    cin >> D[1][1] >> D[1][2] >> D[1][3];
    for (int i = 2 ; i <= n ; i++)
    {
        cin >> D[i][1] >> D[i][2] >> D[i][3];
        D[i][1] += min(D[i-1][2], D[i-1][3]);
        D[i][2] += min(D[i-1][1], D[i-1][3]);
        D[i][3] += min(D[i-1][1], D[i-1][2]);
    }
    cout << min(D[n][1], min(D[n][2], D[n][3])) << '\n';

	return 0;
}