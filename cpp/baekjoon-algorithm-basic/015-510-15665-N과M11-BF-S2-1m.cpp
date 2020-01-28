#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> data;
int used[9] = {0, };

void pick(vector<int> &picked, int length){
    if (length == 0){
        for(int i = 0 ; i < picked.size(); i++)
            cout << picked[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++){
        if (!used[i]){
            picked.push_back(data[i]);
            pick(picked, length-1);
            picked.pop_back();
            while(data[i+1]==data[i]&&i<n)
                i++;
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    data.push_back(-1);
    for (int i = 1 ; i <= n; i++)
    {
        int t; cin >> t;
        data.push_back(t);
    }

    sort(data.begin(), data.end());

    vector<int>picked;
    pick(picked, m);

    return 0;
}