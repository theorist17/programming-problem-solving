#include<iostream>
#include<vector>
using namespace std;

int n;
char arr[50][50];


void swap(int r, int c, int y, int x)
{
    char temp = arr[r][c];
    arr[r][c] = arr[y][x];
    arr[y][x] = temp;
}

int score()
{
    int maxv = 0;
    for (int i = 0 ; i < n; i++ )
    {
        int colScore = 1, rowScore = 0;
        for (int j = 1 ; j < n ; j++)
        {
            if (arr[i][j] == arr[i][j-1])
            {
                colScore += 1;
                rowScore = max(rowScore, colScore);
            }
            else
                colScore = 1;
        }
        maxv = max(maxv, rowScore);
    }

    for (int j = 0 ; j < n ; j++)
    {
        int colScore = 0, rowScore = 1;
        for (int i = 1 ; i < n; i++ )
        {
            if (arr[i][j] == arr[i-1][j])
            {
                rowScore += 1;
                colScore = max(colScore, rowScore);
            }
            else
                rowScore = 1;
        }
        maxv = max(maxv, colScore);
    }

    return maxv;
}

int main() 
{
    cin >> n; cin.ignore();


    string line;
    for (int i = 0 ; i < n ; i++)
    {
        getline(cin, line);
        for (int j = 0 ; j < n ; j ++)
            arr[i][j] = line[j];
    }

    int maxv = 0;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n - 1 ; c++)
        {
            swap(r, c, r, c + 1);
            maxv = max(maxv, score());
            swap(r, c, r, c + 1);
        }
    }

    for (int r = 0; r < n - 1; r++)
    {
        for (int c = 0; c < n; c++)
        {
            swap(r, c, r + 1, c);
            maxv = max(maxv, score());
            swap(r, c, r + 1, c);
        }
    }

    cout << maxv << "\n";
    
    
    return 0;
}