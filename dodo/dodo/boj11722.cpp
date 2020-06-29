#include<iostream>
#include<algorithm>
using namespace std;

int num[1002];
int dp[1002];
int N;
int ans = 1;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		dp[i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (num[i] < num[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}