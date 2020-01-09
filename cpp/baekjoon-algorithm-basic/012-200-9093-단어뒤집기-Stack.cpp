#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> s;
	int T;
	cin >> T;
	cin.ignore();

	string line;
	for (int i = 0 ; i < T ; i++)
	{
		getline(cin, line);
		line += '\n';
		for (int j = 0 ; j < line.length() ; j++)
		{
			if (line[j] == ' ' || line [j] == '\n') 
			{
				while(!s.empty()){
					cout << s.top();
					s.pop();
				}
				cout << line[j];
			} else {
				s.push(line[j]);
			}
		}
	}

	return 0;
}