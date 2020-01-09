#include<iostream>
#include<string>
using namespace std;

class Stack
{
private:
	int A[10000], m;
public:
	Stack() { m = 0; }
	void push(int n){
		if (m == 100000)
			return;
		A[m] = n;
		m += 1;
	}
	int pop() {
		if (empty())
			return -1;
		int ret = A[m-1];
		m -= 1;
		return ret;
	}
	int top() {
		if (empty())
			return -1;
		return A[m-1];
	}
	int empty() {
		if (m == 0)
			return 1;
		else 
			return 0;
	}
	int size() {
		return m;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Stack s;

	int N;
	cin >> N;

	for (int i = 0 ; i < N ; i++){
		string str;
		cin >> str;
		
		if (!str.compare("push")){
			int op;
			cin >> op;
			cin.ignore();
			s.push(op);
		} else if (!str.compare("pop")){
			cout << s.pop() << '\n';
		} else if (!str.compare("top")){
			cout << s.top() << '\n';
		} else if (!str.compare("empty")){
			cout << s.empty() << '\n';
		} else if (!str.compare("size")){
			cout << s.size() << '\n';
		}
	}
	return 0;
}