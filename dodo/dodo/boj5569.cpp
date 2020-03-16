#include<iostream>
#include<algorithm>
using namespace std;

int dp[110][110][2][2] = { 0 };
int W,H;
int ans = 0;
int main() {
	cin >> W >> H;
	for (int i = 2; i <= W; i++)
		dp[i][1][0][0] = 1;
	for (int i = 2; i <= H; i++)
		dp[1][i][1][0] = 1;
	for (int i = 2; i <= W; i++) {
		for (int j = 2; j <= H; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % 100000;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % 100000;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans += dp[W][H][i][j];
		}
	}
	cout << ans%100000 << '\n';
	return 0;
}