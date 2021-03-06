#include<iostream>
#include<vector>
using namespace std;

bool prevPermutation(vector<int>&v){
    int a, b, n = v.size();

    // find a-1 & a (crossing index a)
    for (a = n-1; a > 0 ; a--)
        if(v[a-1]>v[a])
            break;
    if (a==0) // decreasing order : last permutation
        return false;
    
    // find v[a-1] < v[b] (crossing value b)
    for (int i = a; i < n; i++)
        if (v[a-1] > v[i])
            b = i;
    
    // swap(a-1, b)
    int t = v[a-1];
    v[a-1] = v[b];
    v[b] = t;

    // reverse [a, n)
    int i = a, j = n-1;
    while(i < j) {
        t = v[i];
        v[i] = v[j];
        v[j] = t;
        i += 1; j -= 1;
    }

    return true;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if(prevPermutation(v)) {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
    

    return 0;
}