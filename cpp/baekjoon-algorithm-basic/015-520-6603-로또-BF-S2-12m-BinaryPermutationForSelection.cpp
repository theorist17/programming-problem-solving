#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
    while(true)
    {
        int k;
        cin >> k;
        if (k == 0)
            break;
        vector<int> s(k);
        for (int i = 0; i < k; i++)
            cin >> s[i];
        
        // binary permutaion : k! / (6! * (k-6)!)
        vector<bool> p(k, true);
        for (int i = 0; i < 6; i++)
            p[i] = false;
        
        do {
            for (int i = 0; i < k; i++)
                if (!p[i])
                    cout << s[i] << " ";
                cout << '\n';
        } while(next_permutation(p.begin(), p.end()));

        cout << '\n';
    }
    

    return 0;
}