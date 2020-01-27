#include<iostream>
#include<string>
using namespace std;

char board[5][5];
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool hasWord(int y, int x, const string& word)
{
    return 0;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c;
    cin >> c; cin.ignore();
    while(c--)
    {   
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0 ; j < 5; j++)
                cin.get(board[i][j]);
            cin.ignore();
        }

        int n;
        cin >> n; cin.ignore();
        
        while(n--)
        {
            string word;
            getline(cin, word);
            
            bool flag = false;
            for(int r = 0 ; r < 5; r++)
                for(int c = 0; c < 5; c++)
                    if(hasWord(r, c, word))
                        flag = true;
            if (flag)
                cout << word << " YES" << '\n';
            else
                cout << word << " NO" << '\n';
        }
    }
    return 0;
}