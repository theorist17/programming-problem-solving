#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 1;
    while(n)
        a *= n--;
    cout << a << '\n';
    return 0;
}