#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string S;
    vector<int> alphabet(26, 0);
    getline(cin, S);
    for (char ch : S)
        alphabet[ch-'a']++;
    for (int count : alphabet)
        cout << count << " ";
    cout << "\n";
    
    
	return 0;
}