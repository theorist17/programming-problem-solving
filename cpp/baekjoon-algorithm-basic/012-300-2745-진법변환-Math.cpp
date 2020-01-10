#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	string n;
    int b, a=0;
    cin >> n >> b;

    
    for (int i = n.length()-1, k=0; i >= 0 ; i--, k++)
    {
        if ('A' <= n[i] && n[i] <='Z')
        {
            a += pow(b, k) * (n[i] - 'A' + 10);
        } 
        else 
        {
            a += pow(b, k) * (n[i] - '0');
        }
    }

    cout << a << '\n';

	return 0;
}