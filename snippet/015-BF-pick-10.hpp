#include<iostream>
#include<vector>
using namespace std;

void printVec(const vector<int>& vec );

void pick(vector<int>& arr, vector<int>& ret, int pickedIdx, int toPick)
{
    if (toPick == 0){
        //printVec(ret);
        return;
    }

    for (int i = pickedIdx + 1; i < arr.size(); i++)
    {
        ret.push_back(arr[i]);
        pick(arr, ret, i, toPick - 1);
        ret.pop_back();
    }
}


void printVec(const vector<int>& vec )
{
    for (int i = 0 ; i < vec.size(); i++) 
        cout << vec[i] << ' '; 
    cout << '\n';
}