#include<iostream>
using namespace std;

int main()
{
    long long D[100001][3];
    D[1][0] = 1; D[1][1] = 0; D[1][2] = 0;
    D[2][0] = 0; D[2][1] = 1; D[2][2] = 0;
    D[3][0] = 1; D[3][1] = 1; D[3][2] = 1;
    
    for(int i = 4; i <= 100000; i++)
    {
        D[i][0] = (D[i-1][1] + D[i-1][2]) % 1000000009;
        D[i][1] = (D[i-2][0] + D[i-2][2]) % 1000000009;
        D[i][2] = (D[i-3][0] + D[i-3][1]) % 1000000009;
    }
    
    int t; cin >> t;
    while(t--)
    {
        int i; cin >> i;
        long long a = 0;
        a = (a + D[i][0]) % 1000000009;
        a = (a + D[i][1]) % 1000000009;
        a = (a + D[i][2]) % 1000000009;
        cout << a << '\n';
    }

	return 0;
}