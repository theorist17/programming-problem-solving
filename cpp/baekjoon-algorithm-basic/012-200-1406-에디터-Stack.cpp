#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> left, right;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length() ; i++)
		left.push(s[i]);
	
	int M;
	cin >> M;
	for (int i = 0 ; i < M ; i++)
	{
		cin >> s;
		if(s == "L")
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		} 
		else if(s == "D")
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		} 
		else if(s == "B")
		{
			if(!left.empty())
				left.pop();
		} 
		else if (s == "P")
		{
			char ch;
			cin >> ch;
			left.push(ch);
		}
	}

	while(!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while(!right.empty())
	{
		cout << right.top();
		right.pop();
	}
	cout << '\n';
	return 0;
}