#include<iostream>
#include<vector>
using namespace std;

int n, m;

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
        arr.push_back(i);
        pick(arr, i, toPick - 1);
        arr.pop_back();
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<int> arr;
    pick(arr, 0, m);

    return 0;
}