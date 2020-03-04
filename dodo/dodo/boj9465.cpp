#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
/*
스티커를 때서 최대점수를 획득해야됨, 스티커를 때면 상하좌우는 이용하지 못함

우하향,우상향,건너뛰기 3가지를 수행가능

*/
int map[2][100002] = { 0 };
int dp[2][100002] = { 0 };//0은 우하향, 1 우상향 2 건너뛰기
int T, N;

void solve() {
	for (int i = 0; i< N; i++) {
		//우하향 방향
		dp[1][i+1] = max(dp[0][i] + map[1][i+1], dp[1][i+1]);
		//우상향 
		dp[0][i+1]=max(dp[1][i] + map[0][i+1], dp[0][i+1]);
		//건너뛰기
		if (i+2<=N) {
			//2칸전 우하향 
			dp[0][i+2] = max(dp[1][i] + map[0][i+2], dp[0][i] + map[0][i+2]);
			dp[1][i+2] = max(dp[1][i] + map[1][i+2], dp[0][i] + map[1][i+2]);
		}
	}
}
int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		solve();
		cout << max(dp[0][N], dp[1][N])<<'\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}