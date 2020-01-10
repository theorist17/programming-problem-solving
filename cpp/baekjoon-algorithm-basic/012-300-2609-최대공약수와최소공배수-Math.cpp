#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}
int main()
{
    int a, b, g;
    cin >> a >> b;
    g = gcd(a, b);
    cout << g << '\n' << a * b / g <<  '\n'; 

	return 0;
}