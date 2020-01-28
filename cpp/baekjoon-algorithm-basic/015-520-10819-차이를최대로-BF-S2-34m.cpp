#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    int maxv = 0;
    do {
        int sum = 0;
        for(int i = 0 ; i < n-1; i++)
            sum += abs(v[i] - v[i+1]);
        maxv = max(maxv, sum);
    } while(next_permutation(v.begin(), v.end()));
    cout << maxv << "\n";

    return 0;
}