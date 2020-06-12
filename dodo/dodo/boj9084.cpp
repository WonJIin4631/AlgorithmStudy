#include<iostream>
#include<cstring>
using namespace std;
int T, N,M;
int coin[21];
int dp[10001];
int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		cin >> M;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout<< dp[M]<<'\n' ;
	}
	return 0;
}