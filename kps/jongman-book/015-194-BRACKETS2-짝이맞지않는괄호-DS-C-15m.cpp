#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main() 
{
    int c;
    cin >> c; cin.ignore();

    string line;
   
    while(c--) {
        getline(cin, line);

        stack<char> s;
        for (int i = 0 ; i < line.size(); i++)
            if(s.empty())
                s.push(line[i]);
            else 
                if ((line[i]==')' && s.top()=='(') || (line[i] == '}' && s.top() == '{') || (line[i] == ']' && s.top() == '['))
                    s.pop();
                else //if (line[i] == '(' || line[i] == '{' || line[i] == '[')
                    s.push(line[i]);
                
        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}