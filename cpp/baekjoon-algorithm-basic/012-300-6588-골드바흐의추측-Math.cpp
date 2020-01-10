#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const int MAX = 1000000;
// int find(vector<long> &V, int n, int l, int r)
// {
//     if (l == r) return l;
//     int m = l + (r - l) / 2; cout << V[l] << " " << V[m] << " " << V[r] << '\n';
//     if (V[m]==n) return m;
//     else if (V[m] > n) return find(V, n, l, m - 1);
//     else if (V[m] < n) return find(V, n, m + 1, r);
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> C(MAX+1, false);
    vector<int> P;

    for (long i = 2; i <= MAX; i++)
    {
        if (!C[i])
        {
            P.push_back(i);
            for (long j = i*i; j <= MAX; j+=i)
                C[j] = true;
        }
    }

    int n;
    while(cin >> n, n != 0)
    {
        for (int p : P)
        {
            if (!C[n - p])
            {
                cout << n << " = " << p << " + " << n - p << "\n"; break;
            }   
        }
    }
	return 0;
}