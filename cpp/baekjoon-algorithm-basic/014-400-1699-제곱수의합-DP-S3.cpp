#include<iostream>
#include<vector>
using namespace std;

# https://www.acmicpc.net/source/share/454e58d9e21a4042ba74ec9af82c13a4

int main()
{
    int n;
    cin >> n;

    vector<int> D(n+1, -1);
    D[0] = 0;
    D[1] = 1;
    for (int i = 1 ; i * i <= n ; i++)
        D[i*i] = 1;
    

    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (D[i]==-1)
                D[i] = D[j*j] + D[i - j*j];
            else 
                D[i] = min(D[i], D[j*j] + D[i - j*j]);
        }
    }
         
    cout << D[n] << '\n';
    
	return 0;
}