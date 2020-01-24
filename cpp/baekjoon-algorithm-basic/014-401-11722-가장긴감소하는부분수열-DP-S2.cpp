#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<int> A(n+1), D(n+1, 1);

    for (int i = 1; i <= n ; i++)
    {
        cin >> A[i];
        for (int j = i; j >= 1; j--)
        {
            if (A[j] > A[i] && D[j] + 1 > D[i])
            {
                D[i] = D[j] + 1;
            }
        }
    }

    int maxv = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if(maxv < D[i])
            maxv = D[i];
    }
    cout << maxv << ' ';

	return 0;
}