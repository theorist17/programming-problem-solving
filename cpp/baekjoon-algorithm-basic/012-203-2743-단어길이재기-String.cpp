#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string S;
    cout.flush();
    getline(cin, S);

    for (char ch : S)
    {
        if ('a' <= ch && ch <= 'z')
        {
            ch = 'a' + (ch - 'a' + 13) % 26;
        } 
        else if ('A' <= ch && ch <= 'Z')
        {
            ch = 'A' + (ch - 'A' + 13) % 26;
        }
        cout << ch ;
    }

    cout <<'\n';
 
	return 0;
}