#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    stack<char> s;
    string S;
    getline(cin, S);
    S += '\n';
    bool tag = false;
    for (char ch : S)
    {
        if (ch == '<')
        {
            while(!s.empty())
            {
                cout << s.top(); s.pop();
            }
            cout << ch;
            tag = true;
        }
        else if (ch == '>')
        {
            tag = false;
            cout << ch;
        }
        else if (tag)
        {
            cout << ch;
        }
        else if (ch == ' ' || ch == '\n')
        {
            while(!s.empty())
            {
                cout << s.top(); s.pop();
            }
            cout << ch;
        }
        else
        {
            s.push(ch);
        }
    }

	return 0;
}