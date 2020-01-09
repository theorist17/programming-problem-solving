#include<iostream>
#include<string>
using namespace std;

const int MAX = 1e5;

// class Deque
// {
// private:
// 	int d[MAX], f, r;
// public:
// 	Deque() { f = 0; r = 0; }
// 	void push_front(int n){
// 		d[f] = n;
// 		f = (f - 1 + MAX) % MAX;
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

class Deque {
private:
    int data[MAX];
    int index_front;
    int index_back;
public:
    Deque();
    bool empty();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int front();
    int back();
    int size();
};

Deque::Deque() {
    index_front = 0;
    index_back = 0;
}

bool Deque::empty() {
    return index_front == index_back;
}

void Deque::push_front(int x) {
    data[index_front] = x;
    index_front = (index_front-1+MAX) % MAX;
}

void Deque::push_back(int x) {
    index_back = (index_back+1) % MAX;
    data[index_back] = x;
}

int Deque::pop_front() {
	if (empty())
		return -1;
	int ret = data[index_front];
    index_front = (index_front+1) % MAX;
	return ret;
}

int Deque::pop_back() {
	if (empty())
		return -1;
    int ret = data[index_back];
	index_back = (index_back-1+MAX) % MAX;
	return ret;
}

int Deque::front() {
	if (empty())
		return -1;
    return data[(index_front+1)%MAX];
}

int Deque::back() {
	if (empty())
		return -1;
    return data[index_back];
}

int Deque::size() {
	if (empty())
		return -1;
    return (index_back-index_front+MAX)%MAX;
}

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
		
		if (!str.compare("push_back")){
			int op;
			cin >> op;
			cin.ignore();
			s.push_back(op);
		} else if (!str.compare("push_front")){
			int op;
			cin >> op;
			cin.ignore();
			s.push_front(op);
		} else if (!str.compare("pop_front")){
			cout << s.pop_front() << '\n';
		} else if (!str.compare("pop_back")){
			cout << s.pop_back() << '\n';
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