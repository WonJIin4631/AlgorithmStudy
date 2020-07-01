#include<iostream>
using namespace std;

int N, M;
int money[100001];
int ans = 0;
bool cal(int n) {
	int cnt = 1;
	int sum = n;
	for (int i = 0; i < N; i++) {
		if (n < money[i])
			return false;
		if (sum - money[i]<0) {
			sum = n;
			cnt++;
		}
		sum -= money[i];
	}
	if (M >= cnt)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int l = 1; int r = 0;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		r += money[i];
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cal(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}