#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1000001

int main() 
{
    int n;
    cin >> n;
    vector<vector<int> > w(n, vector<int>(n));
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> w[i][j];
            if (i!=j&&w[i][j]==0)
                w[i][j] = INF;
        }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << w[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < n; i++)
        v[i] = i;

    int minv = INF*100;
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += w[v[i]][v[i+1]];
        sum += w[v[n-1]][v[0]];
        minv = min(minv, sum);
    } while(next_permutation(v.begin(), v.end()));
    cout << minv << '\n';

    return 0;
}