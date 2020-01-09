#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    
    int left_min, left_max, right_min, right_max;
    cin >> left_min >> right_max;
    left_max = left_min;
    right_min = right_max;
    cout << left_min + right_max << '\n';
    n--;

    while(n--)
    {
        int a, b;
        cin >> a >> b;

        if (a < left_min)
            left_min = a;
        if (left_max < a)
            left_max = a;
        if (b < right_min)
            right_min = b;
        if (right_max < b)
            right_max = b;

        cout << max(left_min + right_max, left_max + right_min) << '\n';
    }

	return 0;
}