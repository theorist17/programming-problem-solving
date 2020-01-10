#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> V(n);
        for(int i = 0 ; i < n; i++)
            cin >> V[i];

        long sum = 0;
        for(int i = 0 ; i < n-1; i++)
            for (int j = i+1 ; j < n; j++)
                sum += gcd(V[i],V[j]);
        
        cout << sum << '\n';
    }
	return 0;
}