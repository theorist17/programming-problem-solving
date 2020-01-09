#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i = 0;
	cin >> n;

	stack<int> s;
	string ans;
	int x;
	while(n--)
	{
		cin >> x;
		if (i <= x)
		{
			while(i != x)
			{
				s.push(++i);
				ans += "+\n";
			}
			s.pop();
			ans += "-\n";
		}
		else if(x < i)
		{
			bool found = false;
			if (!s.empty())
			{
				if(s.top()==x)
				{
					found = true;
					s.pop();
					ans += "-\n";
				}
			}
			if (!found) {
				cout << "NO\n";
				return 0;
			}
	
		}
	}
	
	cout << ans << '\n';

	return 0;
}