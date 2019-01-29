#include<iostream>
#include<deque>
#include<string>
using namespace std;

deque<int> dq;
void push_back(int n) {
	dq.push_back(n);
}
void push_front(int n) {
	dq.push_front(n);
}
void pop_back() {
	if (dq.empty()) {
		cout << "-1" << endl;
	}
	else {
		cout << dq.back() << endl;
		dq.pop_back();
	}
}
void pop_front() {
	if (dq.empty()) {
		cout << "-1" << endl;
	}
	else {
		cout << dq.front() << endl;
		dq.pop_front();
	}
}
void size() {
	cout << dq.size() << endl;
}
void empty() {
	cout << dq.empty() << endl;
}
void front() {
	if (dq.empty()) {
		cout << "-1" << endl;
	}
	else
		cout << dq.front() << endl;

}
void back() {
	if (dq.empty()) {
		cout << "-1" << endl;
	}
	else 
		cout << dq.back() << endl;
}
int main() {
	int N;
	string s;
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push_back") {
			cin >> a;
			push_back(a);
		}
		if (s == "push_front") {
			cin >> a;
			push_front(a);
		}
		if (s == "front")
			front();
		if (s == "back")
			back();
		if (s == "size")
			size();
		if (s == "pop_front")
			pop_front();
		if (s == "pop_back")
			pop_back();
		if (s == "empty")
			empty();
	}
}