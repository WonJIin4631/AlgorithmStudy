#include<iostream>
#include<queue>
#include<functional>
using namespace std;

priority_queue<int,vector<int>,greater<>> pq;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
	return 0;
}