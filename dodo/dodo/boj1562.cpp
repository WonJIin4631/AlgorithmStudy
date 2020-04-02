#include<iostream>
using namespace std;

#define mod 1000000000
int dp[101][11][1<<10] = { 0 };
int N;

int main() {
	cin >> N;
	int full = (1 << 10) - 1;

	for (int j = 1; j <= 9; ++j)
		dp[1][j][1 << j] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= full; ++k) {
				if (j == 0)
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; ++i) {
		ans = (ans + dp[N][i][full]) % mod;
	}
	cout << ans << '\n';
	return 0;
}