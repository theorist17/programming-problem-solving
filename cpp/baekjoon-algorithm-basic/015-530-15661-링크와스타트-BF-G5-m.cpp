#include<iostream>
#include<vector>
using namespace std;
const int INF = 987654321;
int s[20][20];
int minDiff(int idx, int& n, vector<int>& start, vector<int>& link) {
    // all picked
    if (idx == n) {
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
    if (idx > n)
        return INF;

    // pick partner
    int ret = INF;
    if (start.size() < n - 1){
        start.push_back(idx);
        ret = min(ret, minDiff(idx + 1, n, start, link));
        start.pop_back();
    }

    if (link.size() < n - 1){
        link.push_back(idx);
        ret = min(ret, minDiff(idx + 1, n, start, link));
        link.pop_back();
    }

    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    vector<int> start, link;
    cout << minDiff(0, n, start, link) << '\n';
    

    return 0;
}