#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;

    stack<char> s;

    while(n!=0)
    {
        int r = n % b;
        char d;
        if (r >= 10)
            d = 'A' + r - 10;
        else
            d = '0' + r;
        s.push(d);
        n /= b;
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

	return 0;
}