#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int t, a, b, g;
    cin >> t;

    while(t--)
    {
        cin >> a >> b;
        g = gcd(a, b);
        cout << a * b / g <<  '\n';
    }

	return 0;
}