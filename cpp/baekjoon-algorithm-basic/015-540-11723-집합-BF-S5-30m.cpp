#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, x;
    string cmd;
    cin >> m;

    int set = 0;

    while(m--){
        cin >> cmd;

        if (cmd == "add"){
            cin >> x; 
            set |= (1 << x - 1);
        } else if (cmd == "remove") {
            cin >> x;
            set &= ~(1 << x - 1);
        } else if (cmd == "check") {
            cin >> x;
            if ((set & (1 << x - 1))!=0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (cmd == "toggle"){
            cin >> x;
            set ^= (1 << x - 1);
        } else if (cmd == "all") {
            set |= (1 << 20) - 1;
        } else if (cmd == "empty") {
            set &= 0;
        }
    }

    return 0;
}