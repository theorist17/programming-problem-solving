#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int n, s;
    cin >> n >> s;
    int ans, a;
    cin >> ans;
    ans = abs(ans-s);
    for (int i = 1 ; i < n ; i++)
    {
        cin >> a;
        ans = gcd(ans, abs(a-s));
    }
    cout << ans << '\n';

	return 0;
}