#include<iostream>
#include<vector>
#include<string>
#define MAX 11
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a = 0;
	cin >> t;
	cin.ignore();

	string ref, str;
	int R[26], S[26];

	getline(cin, ref);
	for (int i = 0; i < 26; i++)
		R[i] = 0;
	for (int i = 0 ; i < ref.length(); i++)
		R[ref[i] - 'A']++;
	
	for (int i = 1 ; i < t ; i++)
	{
		getline(cin, str);

		for (int j = 0; j < 26; j++)
			S[j] = 0;
		for (int j = 0 ; j < str.length(); j++)
			S[str[j] - 'A']++;

		int counter = 0;
		for (int j = 0; j < 26; j++)
			counter += abs(R[j] - S[j]);
			
		if (abs((int)ref.length() - (int)str.length()) <= 1 && counter <= 2)
			a++;
	}

	cout << a << '\n';

	return 0;
}