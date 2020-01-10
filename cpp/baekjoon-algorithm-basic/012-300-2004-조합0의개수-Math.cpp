#include<iostream>
using namespace std;

int main()
{
    long long n, m, i;
    cin >> n >> m;

    int five = 0;
    for ( i = 5; i <= n; i*=5)
        five += n / i;
    for ( i = 5; i <= m; i*=5)
        five -= m / i;
    for ( i = 5; i <= n - m; i*=5)
        five -= (n - m) / i;

    int two = 0;
    for ( i = 2; i <= n; i*=2)
        two += n / i;
    for ( i = 2; i <= m; i*=2)
        two -= m / i;
    for ( i = 2; i <= n - m; i*=2)
        two -= (n - m) / i;

    cout << min(five, two) << '\n';

    return 0;
}