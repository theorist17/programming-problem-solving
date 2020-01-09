#include<iostream>
#include<string>
using namespace std;

const int MAX = 1e5;

// class Deque
// {
// private:
// 	int d[MAX], f, r;
// public:
// 	Deque() { f = -1; r = 0; }
// 	void push_front(int n){
// 		d[++f] = n;
// 	}
// 	void push_back(int n){
// 		r = (r+1) % MAX;
// 		d[r] = n;
// 	}
// 	int pop_front() {
// 		if (empty())
// 			return -1;
// 		int ret = d[f++];
// 		f = (f + 1) % MAX;
// 		return ret;
// 	}
// 	int pop_back() {
// 		if (empty())
// 			return -1;
// 		int ret = d[f++];
// 		r = (r - 1 + MAX) % MAX;
// 		return ret;
// 	}
// 	int size() {
// 		return (r - f + MAX) % MAX;
// 	}
// 	bool empty() {
// 		if (f == r)
// 			return true;
// 		else 
// 			return false;
// 	}
// 	int front() {
// 		if (empty())
// 			return -1;
// 		return d[(f+1)%MAX];
// 	}
// 	int back() {
// 		if (empty())
// 			return -1;
// 		return d[r];
// 	}
// };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Deque s;

	// int N;
	// cin >> N;

	// for (int i = 0 ; i < N ; i++){
	// 	string str;
	// 	cin >> str;
		
	// 	if (!str.compare("push_back")){
	// 		int op;
	// 		cin >> op;
	// 		cin.ignore();
	// 		s.push_back(op);
	// 	} else if (!str.compare("push_front")){
	// 		int op;
	// 		cin >> op;
	// 		cin.ignore();
	// 		s.push_front(op);
	// 	} else if (!str.compare("pop_front")){
	// 		cout << s.pop_front() << '\n';
	// 	} else if (!str.compare("pop_back")){
	// 		cout << s.pop_back() << '\n';
	// 	} else if (!str.compare("empty")){
	// 		cout << s.empty() << '\n';
	// 	} else if (!str.compare("size")){
	// 		cout << s.size() << '\n';
	// 	} else if (!str.compare("front")){
	// 		cout << s.front() << '\n';
	// 	} else if (!str.compare("back")){
	// 		cout << s.back() << '\n';
	// 	} 
	// }
	return 0;
}