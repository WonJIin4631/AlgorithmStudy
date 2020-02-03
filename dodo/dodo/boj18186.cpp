#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
/*
N개의 라면 공장 i번에서는  A개의 라면을 구매

3가지 방법으로 라면구매
1번 i번 공장에서 라면을 하나 구매 B원
2번 i번 공장과 (i+1)번 공장 각각 라면 하나 구매 (B+C)원
3번 i번 공장과 (i+1)번 공장, (i+2)번 공장 각각 라면 하나 구매 (B+2C)
최소금액 출력
DP문제 같음
i번의 공장까지의 지출 금액보다 적은 방법으로 라면 구매
혹시 BFS?
1번 2번 3번 방법으로 끝까지

*/


int main() {
	int N, B, C;
	int lamen[100002];
	cin >> N >> B >> C;
	for (int i = 1; i <= N; i++) {
		cin >> lamen[i];
	}
	long long dp[3][1000002] = { 0 };

	for (int i = 0; i < 3; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= N; i++) {
		dp[0][i] = (B*lamen[i]);
		if (i >= 2) {
			int maxCnt = max(lamen[i - 1], lamen[i]);
			dp[1][i] = (B + C)*maxCnt;
		}
		if (i >= 3) {
			int maxCnt = max(lamen[i - 1], lamen[i]);
			maxCnt = max(maxCnt, lamen[i-2]);
			dp[2][i] =  (B + 2*C)*maxCnt;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << '\n';
		long long temp = min(dp[0][i], dp[1][i]);
		temp = min(temp, dp[2][i]);
		ans += temp;
	}
	cout << ans << '\n';
	return 0;
}