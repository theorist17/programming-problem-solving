#include<iostream>
#include<string>
using namespace std;

const int N = 1e5;

class Deque
{
private:
	int a[N], f, r, s;
public:
	Deque() { f = - 1; r = 0; s = 0;}
	void push_front(int n){
		if (full()) return;
		if (f == -1) f = 0, r = 0;
		else f = (f - 1 + N) % N;
		a[f] = n;
		s++;
	}
	void push_back(int n){
		if (full()) return;
		if (f == -1) f = 0, r = 0;
		else r = (r + 1 + N) % N;
		a[r] = n;
		s++;
	}
	int pop_front() {
		if (empty()) return -1;
		int ret = front();
		if (f == r) f = -1, r = 0;
		else f = (f + 1 + N) % N;
		s--;
		return ret;
	}
	int pop_back() {
		if (empty()) return -1;
		int ret = back();
		if (f == r) f = -1, r = 0;
		else r = (r - 1 + N) % N;
		s--;
		return ret;
	}
	int size() {
		return s;
	}	
	bool full() {
		return (f == r + 1 || (f == 0 && r == N-1));
	}
	bool empty() {
		return f == -1;
	}
	int front() {
		if (empty()) return -1;
		return a[f];
	}
	int back() {
		if (empty()) return -1;
		return a[r];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Deque s;

	int N;
	cin >> N;

	for (int i = 0 ; i < N ; i++){
		string str;
		cin >> str;
		
		if (str == "push_back"){
			int op;
			cin >> op;
			s.push_back(op);
		} else if (str == "push_front"){
			int op;
			cin >> op;
			s.push_front(op);
		} else if (str == "pop_front")
			cout << s.pop_front() << '\n';
		else if (str == "pop_back")
			cout << s.pop_back() << '\n';
		else if (str == "empty")
			cout << s.empty() << '\n';
		else if (str == "size")
			cout << s.size() << '\n';
		else if (str == "front")
			cout << s.front() << '\n';
		else if (str == "back")
			cout << s.back() << '\n';
		else if (str == "full") 
			cout << s.back() << '\n';
	}

	return 0;
}