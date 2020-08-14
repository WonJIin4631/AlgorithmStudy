#include<iostream>
using namespace std;

int N, K;
int dp[11][11] = { 0 };
int main() {
	cin >> N >> K;
	for (int n = 0; n <= N; n++) {
		for (int k = 0; k <= n; k++) {
			if (k == 0 || k == n) {
				dp[n][k] = 1;
			}
			else {
				dp[n][k] = (dp[n - 1][k - 1] + dp[n - 1][k]) % 10007;
			}
		}
	}
	cout << dp[N][K];
	return 0;
}