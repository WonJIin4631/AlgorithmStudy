#include<iostream>
using namespace std;

long long dp[16][16] = { 0 };
int N, M, K;
int main() {
	cin >> N >> M >> K;
	if (K == 0) {
		for (int i = 1; i <= M; i++) {
			dp[1][i] = 1;
		}
		for (int i = 1; i <= N; i++) {
			dp[i][1] = 1;
		}
		for (int i = 1; i <=N; i++) {
			for (int j = 1; j<= M; j++) {
				if (i - 1 >= 1 && j - 1 >= 1) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout << dp[N][M] << '\n';
	}
	else {
		int ky, kx;
		ky = (K / M);
		if (K <= M)
			kx = K;
		else
			kx = K%M;
		if (kx == 0)
			kx = M;
		if (kx != M)
			ky += 1;
		for (int i = 1; i <= kx; i++) {
			dp[1][i] = 1;
		}
		for (int i = 1; i <= ky; i++) {
			dp[i][1] = 1;
		}
		int val1;
		for (int i = 1; i <= ky; i++) {
			for (int j = 1; j <= kx; j++) {
				if (i - 1 >= 1 && j - 1 >= 1) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		val1 = dp[ky][kx];
		for (int i = kx; i <=M; i++) {
			dp[ky][i] = 1;
		}
		for (int i = ky; i <= N; i++) {
			dp[i][kx] = 1;
		}
		for (int i = ky; i <=N; i++) {
			for (int j = kx; j <= M; j++) {
				if (i - 1 >= ky && j - 1 >= kx) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout << val1*dp[N][M] << '\n';
	}
	return 0;
}