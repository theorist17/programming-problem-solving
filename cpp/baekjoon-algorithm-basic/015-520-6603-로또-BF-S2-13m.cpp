#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void pick(vector<int>&s, vector<int>& v, int start, int length){
    if (length == 0){
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start + 1; i < s.size(); i++) {
        v.push_back(s[i]);
        pick(s, v, i, length - 1);
        v.pop_back();
    }
}

int main() 
{
    while(true)
    {
        int k;
        cin >> k;
        if (k == 0)
            break;
        vector<int> s(k), v;
        for (int i = 0; i < k; i++)
            cin >> s[i];
        pick(s, v, -1, 6);
        cout << '\n';
    }
    

    return 0;
}