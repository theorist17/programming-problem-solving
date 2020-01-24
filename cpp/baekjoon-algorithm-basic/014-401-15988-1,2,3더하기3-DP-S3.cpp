#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<long> D(1000001);
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for(int i = 4; i <= 1000000; i++)
    {
        D[i] = D[i-1]; D[i] %= 1000000009;
        D[i] += D[i-2]; D[i] %= 1000000009;
        D[i] += D[i-3]; D[i] %= 1000000009;
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