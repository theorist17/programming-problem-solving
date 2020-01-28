#include<iostream>
#include<string>
#include<vector>
using namespace std;

int switch2clock[10][5] = {
    {0, 1, 2, -1, -1},
    {3, 7, 9, 11, -1},
    {4, 10, 14, 15, -1},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15, -1},
    {3, 14, 15, -1, -1},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

int clocks[16];
int ans;
void pushSwitch(int switchId, int time){
    // time : -3 -2 -1 0 1 2 3
    for(int i = 0; i < 5; i++)
    {
        int clockId = switch2clock[switchId][i];
        if (clockId >= 0)
        {
            clocks[clockId] += 3 * time;
            clocks[clockId] = (clocks[clockId] - 3 + 12) % 12 + 3;
        }
    }
    // for (int i = 0 ; i < 16; i++)
    //     cout << clocks[i] << " ";
    // cout << "\n";
}
void visitSwitch(int idx, int sum){
    // cout << "visitSwitch(" << idx << "," << sum << ")\n";
    if (idx == 9) {
        bool allTwelve = true;
        for (int i = 0 ; i < 16; i++)
            if (clocks[i]!=12)
                allTwelve = false;
        
        if (allTwelve && (ans == -1 || sum < ans))
            ans = sum;

        return;
    }

    for (int i = idx + 1; i < 10; i++) {
        for (int j = 0 ; j < 4; j++){
            sum += j; pushSwitch(i, j);
            if (ans == -1 || sum <= ans)
                visitSwitch(i, sum);
            sum -= j; pushSwitch(i, -j);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c;
    cin >> c;
    while(c--)
    {   
        ans = -1;
        for (int i = 0 ; i < 16; i++)
            cin >> clocks[i];
        visitSwitch(-1, 0);
        cout << ans << "\n";
    }
    return 0;
}