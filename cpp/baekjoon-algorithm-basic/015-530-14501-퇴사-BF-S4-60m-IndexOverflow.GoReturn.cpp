#include<iostream>
using namespace std;

int n;
int t[15], p[15];

int maxProfit(int idx, int sum) {
    if (idx > n)
        return 0;
    
    if (idx == n)
        return sum;
    
    int ret = 0;
    ret = max(ret, maxProfit(idx + t[idx], sum + p[idx]));
    ret = max(ret, maxProfit(idx + 1, sum));
    
    return ret;
}

int main() 
{
    cin >> n;
    for (int i = 0 ; i < n; i++)
        cin >> t[i] >> p[i];
    cout << maxProfit(0, 0) << "\n";
    

    return 0;
}