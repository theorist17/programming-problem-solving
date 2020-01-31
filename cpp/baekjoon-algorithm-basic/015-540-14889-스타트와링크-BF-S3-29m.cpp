#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int s[20][20];
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            cin >> s[i][j];
    
    int ans = 987654321;
    for (int i = 0 ; i < (1 << n) ; i++) {
        int startCnt = 0, linkCnt = 0;
        int startSet = 0, linkSet = 0;
        bool okay = true;
        for (int j = 0 ; j < n ; j++) {
            if ((i & (1 << j)) != 0) {
                startCnt++;
                startSet |= (1 << j);
            } else {
                linkCnt++;
                linkSet |= (1 << j);
            }
            if (startCnt > n / 2 || linkCnt > n / 2){
                okay = false;
                break;
            }
        }
        
        if (okay) {
            int startSum = 0, linkSum = 0;
            for (int j = 0 ; j < n; j++){
                if((startSet & (1 << j)) != 0) {
                    for (int k = 0 ; k < n ; k++){
                        if ((startSet & (1 << k)) != 0){
                            startSum += s[j][k];
                        }
                    }
                } else {
                    for (int k = 0 ; k < n ; k++){
                        if ((linkSet & (1 << k)) != 0){
                            linkSum += s[j][k];
                        }
                    }
                }
            }
            // cout << startSum << " " << linkSum << '\n';
            ans = min(ans, abs(startSum - linkSum));
        }
    }
    
    std::cout << ans << "\n";

    return 0;
}