#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;

    int n, r;
    cin >> n;
    while (n != 0)
    {
        r = n % -2;
        n /= -2;
        if (r < 0)
        {
            n += 1;
            r += 2;
        }

        s.push(r);
    }

    if(s.empty())
        cout << 0;

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << '\n';
    

	return 0;
}