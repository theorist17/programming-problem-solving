#include<iostream>
#include<vector>
using namespace std;

int n, m;

void pick(vector<int>&arr, vector<bool> &chk, int picked, int toPick)
{
    if (toPick == 0)
    {
        for (int i = 0 ; i < arr.size() ; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if(!chk[i])
        {
            arr.push_back(i);
            chk[i] = true;
            pick(arr, chk, i, toPick - 1);
            chk[i] = false;
            arr.pop_back();
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<int> arr;
    vector<bool> chk(n+1, 0);
    pick(arr, chk, 0, m);

    return 0;
}