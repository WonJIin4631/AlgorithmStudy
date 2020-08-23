#include<iostream>
#include<cstdio>
using namespace std;

int N, M;
int dp[1025][1025] = { 0 };
int main() {
	scanf("%d %d", &N, &M);
	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			dp[i][j] = dp[i][j - 1] + num;
		}
	}
	int x1, x2, y1, y2;
	while(M--){
		int ans = 0;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		for (int i = y1; i <= y2; i++) {
			ans += dp[i][x2] - dp[i][x1-1];
		}
		cout << ans << '\n';
	}
	return 0;
}