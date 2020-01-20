#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string B;
    getline(cin, B);

    int o = 0, b;
    stack<int> s;

    for (int i = B.size() - 1, epoch = i % 3, w = 0; i >= 0 ; i--, w++)
    {
        if (epoch == i % 3 && i != B.size() - 1)
        {
            s.push(o);
            o = 0;
        } 
        b = B[i] - '0';         
        b = b << w % 3;
        o += b;
        //cout << o << '\n';
    }
    s.push(o);

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

	return 0;
}