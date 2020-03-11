#include<iostream>
#include<queue>
using namespace std;

bool visited[100001];
int d[100001];

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = true;
    d[n] = 0;

    queue<vector<int> > p;
    vector<int> v;
    p.push(v);

    while(!q.empty()){
        int num = q.front();
        q.pop();
        v = p.front();
        v.push_back(num);
        p.pop();

        if (num == k) {
            cout << d[num] << "\n";
            for (int i = 0 ; i < v.size(); i++)
                cout << v[i] << " ";
            cout << "\n";
            return 0;
        }

        if (num * 2 <= 100000 && !visited[num * 2]){
            d[num * 2] = d[num] + 1;
            q.push(num * 2);
            visited[num * 2] = true;
        }
        if (num + 1 <= 100000 && !visited[num + 1]){
            d[num + 1] = d[num] + 1;
            q.push(num + 1);
            visited[num + 1] = true;
        }
        if (0 <= num - 1 && !visited[num - 1]){
            d[num - 1] = d[num] + 1;
            q.push(num - 1);
            visited[num - 1] = true;
        }
    }

    return 0;
}