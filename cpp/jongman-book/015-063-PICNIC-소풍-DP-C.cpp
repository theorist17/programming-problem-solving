#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
bool areFriend[10][10] = {0, };

int countPairs(bool taken[10]) {
    int firstFree = -1;
    for (int i = 0 ; i < n; i++)
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    
    if (firstFree == -1)
        return 1;
    
    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n ; pairWith++) {
        if (!taken[pairWith] && areFriend[firstFree][pairWith]){

            taken[firstFree] = taken[pairWith] = true;
            ret += countPairs(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c; 
    cin >> c;

    while(c--)
    {
        int m;
        cin >> n >> m;

        // read
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n; j++)
                areFriend[i][j] = 0;

        for (int i = 0 ; i < m ; i++)
        {
            int a, b;
            cin >> a >> b;
            areFriend[a][b] = 1;
            areFriend[b][a] = 1;
        }

        // exhaustive search
        bool taken[10] = {0,};
        int ans = countPairs(taken);
        cout << ans << "\n";
    }
    
    return 0;
}