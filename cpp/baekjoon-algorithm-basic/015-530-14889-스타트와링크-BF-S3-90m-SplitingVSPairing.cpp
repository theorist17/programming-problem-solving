#include<iostream>
#include<vector>
using namespace std;
const int INF = 987654321;
int s[20][20];
int minDiff(vector<bool>& taken, int idx, int length) {
    // all picked
    if (length == 0) {
        vector<int> start, link;
        for (int i = 0 ; i < taken.size() ; i++)
            if (taken[i])
                start.push_back(i);
            else
                link.push_back(i);
        
        int ret = 0;
        for (int i = 0; i < start.size(); i++)
            for (int j = i; j < start.size(); j++)
                ret += s[start[i]][start[j]] + s[start[j]][start[i]];
        for (int i = 0; i < link.size(); i++)
            for (int j = i; j < link.size(); j++)
                ret -= s[link[i]][link[j]] + s[link[j]][link[i]];
        if (ret < 0) ret = -ret;
        return ret < 0 ? -ret : ret;
    }
    if (idx >= taken.size())
        return INF;

    // pick partner
    int ret = INF;
    taken[idx] = true;
    ret = min(ret, minDiff(taken, idx + 1, length - 1));
    taken[idx] = false;
    ret = min(ret, minDiff(taken, idx + 1, length));

    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    vector<bool> taken(n, false);
    cout << minDiff(taken, 0, n / 2) << '\n';
    

    return 0;
}