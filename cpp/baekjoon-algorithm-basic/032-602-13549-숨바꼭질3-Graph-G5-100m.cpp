#include<iostream>
#include<deque>
using namespace std;

bool visited[100001];
int d[100001];

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> q;
    q.push_back(n);
    visited[n] = true;
    d[n] = 0;


    while(!q.empty()){
        int num = q.front();
        q.pop_front();

        if (num == k) {
            cout << d[num] << "\n";
            return 0;
        }

        if (num * 2 <= 100000 && !visited[num * 2]) {
            d[num * 2] = d[num];
            q.push_front(num * 2);
            visited[num * 2] = true;
        }

        if (num + 1 <= 100000 && !visited[num + 1]){
            d[num + 1] = d[num] + 1;
            q.push_back(num + 1);
            visited[num + 1] = true;
        }
        
        if (0 <= num - 1 && !visited[num - 1]){
            d[num - 1] = d[num] + 1;
            q.push_back(num - 1);
            visited[num - 1] = true;
        }
    }

    return 0;
}