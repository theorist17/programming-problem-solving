#include<iostream>
using namespace std;

int main()
{
    int n, A[1001], D[1001];
    cin >> n;;

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> A[i];
        D[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (A[j] < A[i] && D[i] < D[j] + 1)
                D[i] = D[j] + 1;
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
        if (max < D[i])
            max = D[i];

    cout << max << '\n';

	return 0;
}