#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void go(vector<char>&pool, vector<char>& pw, int idx, int& c, int count, int& l, int vowel, int consonant){
    if (count == l && vowel >= 1 && consonant >= 2){
        for (int i = 0 ; i < l; i++)
            cout << pw[i];
        cout << "\n";
    }
    if (idx >= c || count >= l)
        return;
    pw.push_back(pool[idx]);
    if (pool[idx]=='a'||pool[idx]=='e'||pool[idx]=='i'||pool[idx]=='o'||pool[idx]=='u')
        go(pool, pw, idx + 1, c, count + 1, l, vowel + 1, consonant);
    else
        go(pool, pw, idx + 1, c, count + 1, l, vowel, consonant + 1);
    pw.pop_back();
    go(pool, pw, idx + 1, c, count, l, vowel, consonant);
}

int main() 
{
    int l, c;
    cin >> l >> c;
    vector<char> pool(c), pw;
    for (int i = 0 ; i < c ; i++)
        cin >> pool[i];
    sort(pool.begin(), pool.end());
    go(pool, pw, 0, c, 0, l, 0, 0);

    return 0;
}