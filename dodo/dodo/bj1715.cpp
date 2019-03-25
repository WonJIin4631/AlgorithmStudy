#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int N;
priority_queue<int, vector<int>,greater<int>> dq;
vector<int> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		dq.push(num);
	}
	int ans = 0;
	int cnt = 1;
	while (dq.size()>1) {
		int a = dq.top();
		dq.pop();
		int b = dq.top();
		dq.pop();
		ans += a + b;
		dq.push(a + b);
	}
	cout << ans;
}