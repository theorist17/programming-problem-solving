#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> P(n+1), D(n+1);
    for (int i = 1 ; i <= n ; i++)
        cin >> P[i];
    
    D[1] = P[1];
    for (int i = 2 ; i <= n; i++)
    {
        int M = 0, m;
        for (int j = 1; j <= i; j++)
        {
            m = D[j] + D[i - j];
            if (M < m)
                M = m;
        }
        D[i] = max(M, P[i]);
        cout << D[i] << '\n';
    }


	return 0;
}