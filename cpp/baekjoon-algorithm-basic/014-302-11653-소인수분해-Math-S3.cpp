#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> prime(n+1, true);
    vector<int> P;
    prime[0] = false, prime[1] = false;
    for (long i = 2; i <= n; i++)
    {
        if(prime[i])
        {
            P.push_back(i);
            for(long j = i*i; j <= n; j+=i)
                prime[j] = false;
        }
    }

    for (auto it = P.begin(); it != P.end() && n > 0; it++)
    {
        while (n % *it == 0)
        {
            cout << *it << '\n';
            n /= *it;
        }
    }

	return 0;
}