#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Queue
{
	int index = 0;
	vector<int> q;
public:
	Queue() { q; }
	void push(int n) { q.push_back(n); }
	void pop() {
		if (!q.empty()) {
			cout << q.at(0) << endl;
			q.erase(q.begin());
		}
		else
			cout << "-1" << endl;
	}
	void size() { cout << q.size() << endl; }
	void empty() { if (q.empty()) cout << "1"<<endl;
	else cout << "0" << endl;
	}
	void front() {if(!q.empty())  cout << q.at(0) << endl;  else cout << "-1" << endl; }
	void back() { if (!q.empty())  cout << q.at(q.size()-1) << endl;  else cout << "-1" << endl; }
};

int main() {
	Queue q;
	int num, count=0,b;
	string a;
	
	cin >> num;
	while(count<num) {
		cin >> a;
		if (a == "push") {
			cin >> b;
			q.push(b);
		}
		else if (a == "pop") {
			q.pop();
		}
		else if (a == "size") {
			q.size();
		}
		else if (a == "empty") {
			q.empty();
		}
		else if (a == "front") {
			q.front();
		}
		else if (a == "back") {
			q.back();
		}
		count++;
	}
	
}