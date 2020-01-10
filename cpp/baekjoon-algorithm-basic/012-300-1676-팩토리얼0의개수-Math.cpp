#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = n / 5 + n / 25 + n / 125;
    cout << a << '\n';
    
    return 0;
}