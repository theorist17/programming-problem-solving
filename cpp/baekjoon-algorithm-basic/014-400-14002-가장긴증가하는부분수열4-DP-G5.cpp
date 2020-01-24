#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n, A[1001], D[1001], P[1001];
    cin >> n;

    for (int i = 1 ; i <= n ; i++)
    {
        cin >> A[i];
        D[i] = 1; P[i] = i;
        for (int j = i - 1; j >= 1; j--)
        {
            if (A[j] < A[i] && D[i] < D[j] + 1)
            {
                D[i] = D[j] + 1;
                P[i] = j;
            }
        }
    }

    int max = D[1], idx = 1;
    for (int i = 1; i <= n; i++)
        if (max < D[i])
        {
            max = D[i];
            idx = i;
        }
    
    cout << max << '\n';

    stack<int> s;
    s.push(idx);
    while(s.top() != P[s.top()])
        s.push(P[s.top()]);
    while(!s.empty())
    {
        cout << A[s.top()] << ' ';
        s.pop(); 
    }
    cout << '\n';
    
	return 0;
}