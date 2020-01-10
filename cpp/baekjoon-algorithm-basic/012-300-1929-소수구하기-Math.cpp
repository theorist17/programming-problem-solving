#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<bool> C(n, false);
    vector<int> P;

    for (int i = 2; i <= n; i++)
    {
        if (!C[i])
        {
            if (i >= m)
                P.push_back(i);
            for (int j = i*i; j <= n; j+=i)
                C[j] = true;
        }
    }

    for(int p : P)
    {
        cout << p << '\n';
    }
	return 0;
}