#include<iostream>
using namespace std;

int main() 
{
   
    int t;
    cin >> t;
    while(t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        bool found = false;
        for(int i = x ; i <= m * n ; i += m)
            if ( ((i - 1) % n) + 1 == y)
            {
                found = true;
                cout << i << "\n";
                break;
            }

        if (!found)
            cout << -1 << "\n";
    }
    
    return 0;
}