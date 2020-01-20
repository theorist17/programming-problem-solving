#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string O;
    getline(cin, O);

    stack<int> s;

    int o, b;
    for (int i = O.size()-1; i >= 0; i--)
    {
        o = O[i] - '0';
        int loop = 3;
        while (loop--)
        {
            s.push(o % 2);
            o /= 2;
        }
    }

    while(!s.empty() && !s.top())
        s.pop();

    if (s.empty())
        cout << 0;

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

	return 0;
}