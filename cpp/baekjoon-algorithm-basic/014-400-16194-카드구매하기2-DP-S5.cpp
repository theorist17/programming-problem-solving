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

    D[0] = 10000;
    D[1] = P[1];
    for (int i = 2 ; i <= n; i++)
    {
        int m = 10000, t;
        for (int j = 1; j <= i; j++)
        {
            t = D[j] + D[i - j];
            if (m > t)
                m = t;
        }
        D[i] = min(m, P[i]);
    }

    cout << D[n] << '\n';

	return 0;
}