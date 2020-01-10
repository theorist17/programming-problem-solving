#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int n)
{
    if ( n < 2)
       return false;
    for (int i = 2; i * i <= n ; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N, n, a=0;
    cin >> N;

    while(N--)
    {
        cin >> n;
        if (is_prime(n)) a++;
    }

    cout << a << '\n';

	return 0;
}