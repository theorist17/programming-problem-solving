#include<iostream>
using namespace std;

int main()
{
    int D[12];
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for(int i = 4; i <= 11; i++)
    {
        D[i] = D[i-3] + D[i-2] + D[i-1];
    }
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << D[n] << '\n';
    }

	return 0;
}