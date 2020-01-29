#include<iostream>
#include<vector>
#include<string>
using namespace std;

char rel[10];
long mini = 10000000000;
long maxi = 0;
int maxa[10];
int mina[10];
bool taken[10] = {0, };
vector<int> picked; 

void allEquation(int idx, int k) {
    if (idx == k) {
        long n = 0;
        
        for (int i = 0 ; i < k; i++)
            n = n * 10 + picked[i];

        if (maxi < n){
            maxi = n;
            for (int i = 0 ; i < k ; i++)
                maxa[i] = picked[i];
        }
        if (n < mini){
            mini = n;
            for (int i = 0 ; i < k ; i++)
                mina[i] = picked[i];
        }
        return;
    }

    for (int i = 0 ; i < 10; i++) {
        if (taken[i]) continue;
        if (idx == 0|| (rel[idx-1]=='<' && picked[idx-1] < i) || (rel[idx-1]=='>' && picked[idx-1] > i)) {
            taken[i] = true; picked.push_back(i);
            allEquation(idx + 1, k);
            taken[i] = false; picked.pop_back();
        }
    }

}

int main() {
    int k;
    cin >> k;
    for (int i = 0 ; i < k ; i++)
        cin >> rel[i];
    rel[k] = '\n';

    allEquation(0, k + 1);
    for (int i = 0 ; i < k + 1; i++) 
        cout << maxa[i];
    cout << '\n';
    for (int i = 0 ; i < k + 1 ; i++) 
        cout << mina[i];
    cout << '\n';

    return 0;
}