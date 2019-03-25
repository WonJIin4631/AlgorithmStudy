#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;

struct cmp
{
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {
	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				v.push_back(0);
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
		else
			pq.push(num);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << "\n";
	}
}