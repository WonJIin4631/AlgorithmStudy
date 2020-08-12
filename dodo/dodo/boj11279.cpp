#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;

struct cmp{
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(num);
	}
	return 0;
}