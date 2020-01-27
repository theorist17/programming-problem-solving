#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVec(const vector<int>& vec )
{
    for (int i = 0 ; i < vec.size(); i++) 
        cout << vec[i] << ' '; 
    cout << '\n';
}

bool vectorSum(vector<int>& vec, int targetSum)
{
    int partialSum = 0;
    for(int i = 0 ; i < vec.size(); i++)
        partialSum += vec[i];
    return targetSum == partialSum;
}

int pick(vector<int>& arr, vector<int>& ret, int pickedIdx, int toPick, int targetSum)
{
    if (toPick == 0)
        if (vectorSum(ret, targetSum))        
            return toPick;
    
    for (int i = pickedIdx + 1; i < arr.size(); i++)
    {
        ret.push_back(arr[i]);
        if(pick(arr, ret, i, toPick - 1, targetSum) == 0)
            return 0;
        ret.pop_back();
    }
    return -1;
}

int main() 
{
    vector<int> arr(9), ret;

    int t;
    for (int i = 0 ; i < 9; i++)
        cin >> arr[i];
    
    
    pick(arr, ret, -1, 7, 100);
    sort(ret.begin(), ret.end());
    printVec(ret);

    return 0;

}