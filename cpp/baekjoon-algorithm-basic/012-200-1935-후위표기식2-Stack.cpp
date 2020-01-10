#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    stack<double> s;
    
    int n;
    cin >> n;
    cin.ignore();

    string S;
    getline(cin, S);

    vector<double> V(n);
    for (int i = 0 ; i < n ; i++)
        cin >> V[i];
    
    for (char ch : S)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            s.push(V[ch - 'A']);
        }
        else
        {
            double a, b, c;
            a = s.top(); s.pop();
            b = s.top(); s.pop();
            
            if (ch == '+')
                c = b + a;
            else if (ch == '-')
                c = b - a;
            else if (ch == '*')
                c = b * a;
            else if (ch == '/')
                c = b / a;
            
            s.push(c);
        }
    }
    
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    if (!s.empty())
        cout << s.top() << '\n';
    
	return 0;
}