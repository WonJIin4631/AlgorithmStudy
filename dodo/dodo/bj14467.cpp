#include<iostream>
#include<queue>
using namespace std;

int N;
int cnt = 0;
queue<int> q[100 + 1];

void find() {
	for (int i = 0; i < N; i++) {
		int pos;
		if (!q[i].empty()) {
			pos = q[i].front();
			q[i].pop();
			while (!q[i].empty()) {
				if (pos != q[i].front()) {
					cnt++;
					pos = q[i].front();
				}
				q[i].pop();
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int cow, pos;
		cin >> cow >> pos;
		q[cow].push(pos);
	}
	find();
	cout << cnt << '\n';
}