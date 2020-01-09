#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    stack<int> s;

    int N;
    cin >> N;

    vector<int> A(N);
    cin >> A[0];
    s.push(0);
    for(int i = 1 ; i < N ;i++) 
    {
        cin >> A[i];

        while(!s.empty() && A[s.top()] < A[i]) 
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
    for(int i = 0 ; i < N - 1; i++){
        cout << A[i] << ' ';
    }
    cout << A[N-1] << '\n';
	return 0;
}