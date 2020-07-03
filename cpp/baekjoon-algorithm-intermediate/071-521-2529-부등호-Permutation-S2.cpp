#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> myints {1, 2, 3};
    sort(myints.begin(), myints.end());

    do {
        for (int i = 0 ; i < myints.size(); i++)
            cout << myints[i];
        cout << '\n';
    } while ( next_permutation(myints.begin(),myints.end()) );

    cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

    return 0;
}