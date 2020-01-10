#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    stack<int> s;

    int n;
    cin >> n;

    vector<int> A(n), F(1000001, 0);

    for (int i = 0 ; i < n ; i++){
        cin >> A[i];
        F[A[i]]++;
    }

    for(int i = 0; i < n ;i++) 
    {
        while(!s.empty() && F[A[s.top()]] < F[A[i]]) 
        {
            A[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        A[s.top()] = -1;
        s.pop();
    }

    for(int i = 0 ; i < n - 1; i++){
        cout << A[i] << ' ';
    }
    cout << A[n-1] << '\n';
    
	return 0;
}