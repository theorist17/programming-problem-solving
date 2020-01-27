#include<iostream>
#include<vector>
using namespace std;

int main() 
{
    vector<vector<bool> > a1(1, vector<bool> (4, 1));
    vector<vector<bool> > a2(4, vector<bool>(1, 1));
    vector<vector<bool> > b(2, vector<bool>(2, 1));
    vector<vector<bool> > c1(3, vector<bool>(2, 1));
    vector<vector<bool> > c2(2, vector<bool>(3, 1));
    vector<vector<bool> > c3(3, vector<bool>(2, 1)); 
    vector<vector<bool> > c4(2, vector<bool>(3, 1));
    vector<vector<bool> > c5(3, vector<bool>(2, 1));
    vector<vector<bool> > c6(2, vector<bool>(3, 1));
    vector<vector<bool> > c7(3, vector<bool>(2, 1)); 
    vector<vector<bool> > c8(2, vector<bool>(3, 1));
    vector<vector<bool> > d1(3, vector<bool>(2, 1));
    vector<vector<bool> > d2(2, vector<bool>(3, 1));
    vector<vector<bool> > d3(3, vector<bool>(2, 1));
    vector<vector<bool> > d4(2, vector<bool>(3, 1));
    vector<vector<bool> > e1(2, vector<bool>(3, 1));
    vector<vector<bool> > e2(3, vector<bool>(2, 1));
    vector<vector<bool> > e3(2, vector<bool>(3, 1));
    vector<vector<bool> > e4(3, vector<bool>(2, 1));

    c1[0][1] = 0; c1[1][1] = 0;
    c2[1][1] = 0; c2[1][2] = 0;
    c3[1][0] = 0; c3[2][0] = 0;
    c4[0][0] = 0; c4[0][1] = 0;
    c5[0][0] = 0; c5[1][0] = 0;
    c6[0][1] = 0; c6[0][2] = 0;
    c7[1][1] = 0; c7[2][1] = 0;
    c8[1][0] = 0; c8[1][1] = 0;
    d1[0][1] = 0; d1[2][0] = 0;
    d2[0][0] = 0; d2[1][2] = 0;
    d3[0][0] = 0; d3[2][1] = 0;
    d4[1][0] = 0; d4[0][2] = 0;
    e1[1][0] = 0; e1[1][2] = 0;
    e2[0][1] = 0; e2[2][1] = 0;
    e3[0][0] = 0; e3[0][2] = 0;
    e4[0][0] = 0; e4[2][0] = 0;

    vector<vector<vector<bool> >  > tetromino;
    tetromino.push_back(c1);
    tetromino.push_back(c2);
    tetromino.push_back(c3);
    tetromino.push_back(c4);
    tetromino.push_back(c5);
    tetromino.push_back(c6);
    tetromino.push_back(c7);
    tetromino.push_back(c8);
    tetromino.push_back(d1);
    tetromino.push_back(d2);
    tetromino.push_back(d3);
    tetromino.push_back(d4);
    tetromino.push_back(a1);
    tetromino.push_back(a2);
    tetromino.push_back(b);
    tetromino.push_back(e1);
    tetromino.push_back(e2);
    tetromino.push_back(e3);
    tetromino.push_back(e4);

    // for (int k = 0; k < tetromino.size(); k++)
    // {
    //     cout << k << "\n\n";
    //     for (int i = 0 ; i < tetromino[k].size(); i++)
    //     {
    //         for (int j = 0 ; j < tetromino[k][0].size(); j++)
    //         {
    //             cout << tetromino[k][i][j];
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr(n, vector<int>(m));
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    int maxv = 0;
    for (int k = 0 ; k < tetromino.size(); k++)
    {
        for (int i = 0 ; i < n - tetromino[k].size() + 1; i++)
        {
            for (int j = 0 ; j < m - tetromino[k][0].size() + 1 ; j++)
            {
                int s = 0;
                for (int r = 0; r < tetromino[k].size() ; r++)
                {
                    for (int c = 0; c < tetromino[k][0].size() ; c++)
                    {
                        s += arr[i+r][j+c] * tetromino[k][r][c];
                    }
                }

                if (maxv < s)
                {
                    //cout << i << " " << j << " " << k << "\n";
                    maxv = s;
                }
            }
        }
        
    }
    cout << maxv << "\n";
    

    return 0;
}