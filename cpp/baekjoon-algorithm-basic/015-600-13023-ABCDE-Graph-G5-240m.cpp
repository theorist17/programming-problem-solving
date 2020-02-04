#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > e;
    bool a[2000][2000] = {false, };
    vector<vector<int> > g(n);

    for (int i = 0; i < m; i++) { 
        int here, there;
        cin >> here >> there;

        e.push_back({here, there});
        e.push_back({there, here});

        a[here][there] = a[there][here] = true;

        g[here].push_back(there);
        g[there].push_back(here);
    }

    for (int i = 0 ; i < 2*m ; i++){
        for (int j = 0 ; j < 2*m ; j++){
            int A = e[i].first;
            int B = e[i].second;
            int C = e[j].first;
            int D = e[j].second;

            if (A==B||A==C||A==D||B==C||B==D||C==D) continue;

            if (!a[B][C]) continue;

            for (int E : g[D]){
                if((A==B||B==C||C==D||D==E)) continue;
                cout << 1 << '\n';
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}