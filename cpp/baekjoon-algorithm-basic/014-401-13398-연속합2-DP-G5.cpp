#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> A(n+1);
    vector<vector<int> > D(n+1, vector<int> (2));

    for (int i = 1 ; i <= n ; i++)
        cin >> A[i];
    
    
    D[1][0] = A[1]; D[1][1] = A[1];
    int maxv = max(D[1][0], D[1][1]);

    for (int i = 2; i <= n ; i++)
    {
        D[i][0] = max(D[i-1][0] + A[i], A[i]);
        D[i][1] = max(D[i-1][0], D[i-1][1] + A[i]);
        maxv = max(maxv, max(D[i][0], D[i][1]));
    }

    // for (int i = 1; i <= n ; i++)
    //     cout << D[i][0] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n ; i++)
    //     cout << D[i][1] << " ";
    // cout << "\n";

    cout << maxv << '\n';
    

	return 0;
}