#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int coin[101];
int dp[10002];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin>>coin[i];
	}
	for (int i = 1; i <= K; i++) {
		dp[i] = 100001;
	}
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[K] == 100001)
		cout << -1<<'\n';
	else
		cout << dp[K] << '\n';
	return 0;
}