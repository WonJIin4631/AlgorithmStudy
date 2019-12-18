#include<iostream>
using namespace std;

int n, ans = 0;
bool row[16];
bool toright[31];
bool toleft[31];

void solve(int num) {
	if (num > n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!row[i] && !toright[num + i] && !toleft[n + (num - i) + 1]) {
			row[i] = toright[num + i] = toleft[n + (num - i) + 1] = true;
			solve(num + 1);
			row[i] = toright[num + i] = toleft[n + (num - i) + 1] = false;
		}
	}
}
int main() {
	cin >> n;
	solve(1);
	cout << ans<<'\n';
}