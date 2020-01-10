#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    long m, n;
    cin >> m >> n;

    vector<bool> C(n, false);
    vector<long> P;

    for (long i = 2; i <= n; i++)
    {
        if (!C[i])
        {
            if (i >= m)
                P.push_back(i);
            for (long j = i*i; j <= n; j+=i)
                C[j] = true;
        }
    }

    for(long p : P)
    {
        cout << p << '\n';
    }
	return 0;
}