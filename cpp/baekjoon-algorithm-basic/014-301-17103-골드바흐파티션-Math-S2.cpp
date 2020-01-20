#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<bool> prime(1000001, 1);
    vector<int> P;
    prime[0] = 0, prime[1] = 0;

    for (long i = 2; i <= 1000000; i++)
    {
        if (prime[i])
        {
            P.push_back(i);
            for (long j = i * i; j <= 1000000; j += i)
            {   
                prime[j] = 0;
            }
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int cnt = 0;
        for(auto it = P.begin(); *it <= n / 2 && it != P.end(); it++)
        {
            if (prime[n-*it])
                cnt++;
        }
        cout << cnt << '\n';
    }
    
	return 0;
}