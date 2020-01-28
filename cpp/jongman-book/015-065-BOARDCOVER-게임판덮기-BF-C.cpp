#include<iostream>
using namespace std;

int mask[4][2][3] = {
    {   {0, 1, 0},
        {1, 1, 0}   },
    {   {0, 1, 0},
        {0, 1, 1}   },
    {   {0, 1, 1},  
        {0, 0, 1}   },
    {   {0, 1, 1},
        {0, 1, 0}   }
};
int h, w;
int board[20][20];

void printBoard(){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
bool convolution(pair<int, int>&point, int mask[2][3], int posiNega) {
    int r = point.first, c = point.second;
    
    int ret = true;
    for(int i = 0; i < 2; i++)
        for(int j = -1; j <= 1; j++)
            if (mask[i][j+1])
                if(!(0 <= r && r+i < h && 0 <= c+j && c+j < w))
                    return false;
    for(int i = 0; i < 2; i++){
        for(int j = -1; j <= 1; j++){
            board[r+i][c+j] += mask[i][j+1] * posiNega;
            if(board[r+i][c+j]==2)
                ret = false;
        }
    }
    //printBoard();
    return ret;
}
int addBlock(int length) {
    // search zero-valued point
    pair<int, int> zeroPoint = make_pair(-1, -1);
    for (int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(board[i][j]==0){
                zeroPoint = make_pair(i, j);
                break;
            }
        }
        if(zeroPoint != make_pair(-1, -1))
            break;
    }
    // board[zeroPoint.first][zeroPoint.second] = 2;
    // printBoard();
    // board[zeroPoint.first][zeroPoint.second] = 0;

    // base
    if(length == 0){
        if (zeroPoint == make_pair(-1, -1)){
            //printBoard();
            return 1;
        } else {
            return 0;
        }
    }
    
    // recursive
    int ret = 0;
    for (int i = 0; i < 4; i++){
        if (convolution(zeroPoint, mask[i], 1))
            ret += addBlock(length-1);
        convolution(zeroPoint, mask[i], -1);
    }
    return ret;
}
int main() {
    int c;
    cin >> c;
    while(c--){
        cin >> h >> w;
        int space = 0;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                char t; cin >> t;
                if (t=='#') 
                    board[i][j] = 1;
                else if (t=='.') {
                    board[i][j] = 0;
                    space++;
                }
            }
        }

        // pair<int, int> center = make_pair(0,0);
        // for(int i = 0 ; i < 4; i++){
        //     convolution(center, mask[i], 1);
        //     convolution(center, mask[i], -1);
        // }
        
        if (space % 3 == 0)
            cout << addBlock(space / 3) << "\n";
        else
            cout << 0 << "\n";
        
    }
    
}