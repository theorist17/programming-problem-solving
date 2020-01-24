#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<int> A(n+1), D(n+1, 0);

    for (int i = 1; i <= n ; i++)
    {
        cin >> A[i];
        D[i] = A[i];
        for (int j = i; j >= 1; j--)
        {
            if (A[j] < A[i] && D[j] + A[i] > D[i])
            {
                D[i] = D[j] + A[i];
            }
        }
    }

    int maxv = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        //cout << D[i] << ' ';
        if(maxv < D[i])
            maxv = D[i];
    }
    cout << maxv << ' ';

	return 0;
}