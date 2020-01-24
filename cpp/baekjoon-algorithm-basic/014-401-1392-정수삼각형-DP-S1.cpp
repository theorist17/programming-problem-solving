#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<vector<int> > D(n);
    
    int t;
    cin >> t;
    D[0].push_back(t); D[0].push_back(0);
    for(int i = 1 ; i < n ; i++)
    {
        cin >> t;
        D[i].push_back(t+D[i-1][0]);
        for (int j = 1 ; j <= i; j++)
        {  
            cin >> t;
            t += max(D[i-1][j-1], D[i-1][j]);
            D[i].push_back(t);
        }
    }
    int maxv = 0;
    for (int j = 0; j <= n; j++)
    {
        if (maxv < D[n-1][j])
            maxv = D[n-1][j];
    }

    cout << maxv << '\n';
	return 0;
}