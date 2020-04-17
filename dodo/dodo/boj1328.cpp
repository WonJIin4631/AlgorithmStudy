#include<iostream>
using namespace std;

int main() {
	int N, L, R;
	long long dp[101][101][101];
	cin >> N >> L >> R;
	dp[1][1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int k = 1; k <= R; k++) {
				dp[i][j][k] = dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
				dp[i][j][k] %= 1000000007;
			}
		}
	}
	cout << dp[N][L][R] << '\n';
	return 0;
}