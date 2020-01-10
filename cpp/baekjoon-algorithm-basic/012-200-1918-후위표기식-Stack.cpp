#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    stack<char> s;

    string S;
    getline(cin, S);

    for (char ch : S)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            cout << ch;
        }
        else
        {
            if (ch == '(') 
            {
                s.push(ch);
            }
            else if (ch == ')') {
                while(s.top()!='(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else if (ch == '*' || ch == '/')
            {
                while(!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(ch);
            }
            else if (ch == '+' || ch == '-')
            {
                while(!s.empty() && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(ch);
            }
            
        }
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << '\n';
	return 0;
}