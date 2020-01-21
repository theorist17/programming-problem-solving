#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int D[1001];
    D[0] = 1;
    D[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }
    cout << D[n] << '\n';

	return 0;
}