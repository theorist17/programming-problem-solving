#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
bool chk[9] = {0,};
vector<int> data;

void pick(vector<int>&arr, int picked, int toPick)
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
        if (!chk[i])
        {
            arr.push_back(data[i]);
            chk[i] = true;
            pick(arr, i, toPick - 1);
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
    data.push_back(-1);
    for (int i = 1 ; i <= n; i++)
    {
        int t; 
        cin >> t;
        data.push_back(t);
    }
    sort(data.begin(), data.end());

    pick(arr, 0, m);

    return 0;
}
