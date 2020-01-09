#include<iostream>
#include<string>
using namespace std;

class Queue
{
	int data[10000], begin, end;
public:
	Queue() { begin = 0; end = 0; }
	void push(int n){
		if (end == 100000)
			return;
		data[end++] = n;
	}
	int pop() {
		if (empty())
			return -1;
		int ret = data[begin++];
		return ret;
	}
	int size() {
		return end - begin;
	}
	bool empty() {
		if (begin == end)
			return true;
		else 
			return false;
	}
	int front() {
		if (empty())
			return -1;
		return data[begin];
	}
	int back() {
		if (empty())
			return -1;
		return data[end-1];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Queue s;

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
		} else if (!str.compare("empty")){
			cout << s.empty() << '\n';
		} else if (!str.compare("size")){
			cout << s.size() << '\n';
		} else if (!str.compare("front")){
			cout << s.front() << '\n';
		} else if (!str.compare("back")){
			cout << s.back() << '\n';
		} 
	}
	return 0;
}