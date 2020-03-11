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
    vector<int> t;
    t.push_back(n);
    p.push(t);

    while(!q.empty()){
        int num = q.front();
        q.pop();
        vector<int> v = p.front();
        p.pop();
        cout << num << " : " ;
        for (int i = 0 ; i < v.size(); i++)
                cout << v[i] << " ";
        cout << "\n";
        if (num == k) {
            cout << d[num] << "\n";
            for (int i = 0 ; i < v.size(); i++)
                cout << v[i] << " ";
            cout << num << "\n";
            return 0;
        }

        if (num * 2 <= 100000 && !visited[num * 2]){
            d[num * 2] = d[num] + 1;
            q.push(num * 2);
            visited[num * 2] = true;
            v.push_back(num * 2);
            p.push(v);
            v.pop_back();
        }
        if (num + 1 <= 100000 && !visited[num + 1]){
            d[num + 1] = d[num] + 1;
            q.push(num + 1);
            visited[num + 1] = true;
            v.push_back(num + 1);
            p.push(v);
            v.pop_back();
        }
        if (0 <= num - 1 && !visited[num - 1]){
            d[num - 1] = d[num] + 1;
            q.push(num - 1);
            visited[num - 1] = true;
            v.push_back(num - 1);
            p.push(v);
            v.pop_back();
        }
    }

    return 0;
}