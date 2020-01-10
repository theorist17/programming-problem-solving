#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string S;
    cout.flush();
    while(getline(cin, S))
    {
        int small=0, big=0, num=0, space=0;    
        for (char ch : S) 
        {
            if ('a' <= ch && ch <= 'z')
                small++;
            else if ('A' <= ch && ch <= 'Z')
                big++;
            else if ('0' <= ch && ch <= '9')
                num++;
            else if (ch == ' ')
                space++;
        }
        cout << small << ' ' << big << ' ' << num << ' ' << space << '\n';
        cout.flush();
    }
    
	return 0;
}