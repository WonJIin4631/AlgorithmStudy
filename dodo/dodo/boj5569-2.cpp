#include<iostream>
using namespace std;

#define MOD 100000

int W, H;
int dp[102][102][2][2] = { 0 };//가로좌표,세로좌표,가로에서 블록 이동수,세로에서 블록 이동수 
int ans = 0;
int main() {
	cin >> W >> H;
	for (int i = 2; i <= W; i++)
		dp[i][1][0][0] = 1;
	for (int i = 2; i <= H; i++)
		dp[1][i][1][0] = 1;
	for (int i = 2; i <= W; i++) {
		for (int j = 2; j <= H; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % MOD;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MOD;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans += dp[W][H][i][j];
		}
	}
	cout << ans % MOD << '\n';
	return 0;
}