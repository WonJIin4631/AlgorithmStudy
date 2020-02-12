#include<iostream>
#include<algorithm>
using namespace std;

/*
맨위층에서 맨아래층까지 합을 더하면서 내려감 맨 아래층까지의 합에서 최대값을 출력
아래대각왼, 아래대각오 방향으로 더할수있음

DP사용 
이전에 더해진 최대값으로 계속 더해감
현재 값과 더해진 값과 비교하여 큰값을 유지

*/
int map[501][501];
int dp[501][501] = { 0 };
int N;
int ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = map[0][0];
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], map[i + 1][j] + dp[i][j]);
			dp[i + 1][j+1] = max(dp[i + 1][j+1], map[i + 1][j+1] + dp[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[N - 1][i]);
	}
	cout << ans << '\n';
	return 0;
}