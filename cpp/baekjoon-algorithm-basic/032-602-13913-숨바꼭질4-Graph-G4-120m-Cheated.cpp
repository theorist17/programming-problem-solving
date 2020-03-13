#include<iostream>
#include<queue>
#include<stack>
using namespace std;

bool visited[100001];
int d[100001];
int from[100001];

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = true;
    d[n] = 0;
    from[n] = n;

    while(!q.empty()){
        int num = q.front();
        q.pop();

        if (num == k) {
            cout << d[num] << "\n";
            stack<int> s;
            s.push(num);
            while(s.top() != from[s.top()])
                s.push(from[s.top()]);
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            } cout << "\n";
            return 0;
        }

        if (num * 2 <= 100000 && !visited[num * 2]){
            d[num * 2] = d[num] + 1;
            q.push(num * 2);
            visited[num * 2] = true;
            from[num * 2] = num;

        }
        if (num + 1 <= 100000 && !visited[num + 1]){
            d[num + 1] = d[num] + 1;
            q.push(num + 1);
            visited[num + 1] = true;
            from[num + 1] = num;
        }
        if (0 <= num - 1 && !visited[num - 1]){
            d[num - 1] = d[num] + 1;
            q.push(num - 1);
            visited[num - 1] = true;
            from[num - 1] = num;
        }
    }

    return 0;
}