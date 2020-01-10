#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string S;
    getline(cin, S);
    
    vector<string> V;
    for (int i = 0 ; i < S.length() ; i++)
        V.push_back(S.substr(i, S.length() - i));
    
    sort(V.begin(), V.end());

    for (string s : V)
        cout << s << '\n';
    
	return 0;
}