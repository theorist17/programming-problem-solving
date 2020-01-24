#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<int> A(n+1), D(n+1, 1), P(n+1, 1);

    for (int i = 1; i <= n ; i++)
    {
        cin >> A[i];
        for (int j = i; j >= 1; j--)
        {
            if (A[j] < A[i] && D[j] + 1 > D[i])
            {
                D[i] = D[j] + 1;
            }
        }
    }

    for (int i = n; i >= 1 ; i--)
    {
        for (int j = i; j <= n; j++)
        {
            if (A[i] > A[j] && P[j] + 1 > P[i])
            {
                P[i] = P[j] + 1;
            }
        }
    }

    int maxv = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if(maxv < P[i] + D[i])
            maxv = P[i] + D[i];
    }
    cout << maxv - 1<< '\n';

	return 0;
}