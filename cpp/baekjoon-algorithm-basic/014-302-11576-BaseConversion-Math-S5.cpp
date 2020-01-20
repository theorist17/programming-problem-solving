#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int d;
    cin >> d;

    int n = 0, m;
    for (int i = d-1 ; i >=0; i--)
    {
        cin >> m;
        n += m * pow(a, i);
    }
    
    d = 0;
    while(pow(b, d+1) <= n)
        d++;

    while(d+1)
    {
        int q = pow(b, d);
        cout << n / q << ' ';
        n %= q;
        d--;
    }
    cout << '\n';

	return 0;
}