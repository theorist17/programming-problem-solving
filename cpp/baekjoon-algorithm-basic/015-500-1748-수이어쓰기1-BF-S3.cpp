#include<iostream>
#include<cmath>
using namespace std;

int main() 
{
    int n, t, m = 0;
    cin >> n;
    t = n;

    while(t)
    {
        m++;
        t /= 10;
    }

    int ans = 0;
    for (int i = 0; i < m - 1 ; i++)
    {
        ans += (i+1)*(pow(10, i+1) - pow(10, i));
        //cout << ans << "\n";
    }

    int a = n - pow(10, m - 1) + 1;
    
    ans += a * m;

    cout << ans << "\n";
    
    return 0;
}