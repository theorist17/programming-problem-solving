#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

vector<bool> button(10, true);
int diff, digit;
int n;
void pick(int exp, string str)
{

    for (int i = 0 ; i < 10; i++)
    {
        if (button[i])
        {
            string tempStr = str + (char)('0' + i);
            int closest = stoi(tempStr);
            int localDiff = abs(n-closest);
            int localDigit = to_string(closest).length();
            if (localDiff + localDigit < diff + digit)
            {
                diff = localDiff;
                digit = localDigit;
                //cout << tempStr << " " << diff << " " << digit << '\n';
            }
            if(exp != 0)
                pick(exp-1, tempStr);
        }
    }
}
int main() 
{
    cin >> n;
    diff = abs(100 - n);
    digit = 0;

    int m;
    cin >> m;
    
    while(m--)
    {
        int t;
        cin >> t;
        button[t] = false;
    }
    
    pick(5, "");

    cout << diff + digit << '\n';

    return 0;
}