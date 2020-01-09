#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0 ; i < T ; i++)
	{
		stack<char> s;
		string line;
		getline(cin, line);
		int j;
		for (j = 0 ; j < line.length() ; j++)
		{
			if (line[j] == '(')
			{
				s.push('(');
			}
			else if (line[j] == ')')
			{
				if (s.empty())
				{
					break;
				} 
				else 
				{
					s.pop();
				}
			}
		}
		if (s.empty() && j == line.length())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}