#include<iostream>
using namespace std;


int N;
int ans = -987654321;
char susic[20];

int cal(int a, int b, char op) {
	if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else
		return a*b;
}


void solve(int idx, int val) {
	if (idx >= N) {
		if (ans < val)
			ans = val;
		return;
	}
	int cVal = cal(val, susic[idx + 1] - '0', susic[idx]);
	solve(idx + 2, cVal);
	if (idx + 3 < N) {
		int nVal = cal(susic[idx + 1] - '0', susic[idx + 3] - '0', susic[idx + 2]);
		cVal = cal(val, nVal, susic[idx]);
		solve(idx + 4, cVal);
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> susic[i];
	}
	solve(1, susic[0] - '0');
	cout << ans << '\n';
}