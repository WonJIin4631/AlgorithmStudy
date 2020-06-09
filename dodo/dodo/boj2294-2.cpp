#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int dp[10001] = { 0 };
int money[101] = { 0 };
int main() {
	cin >> N >> K;
	int idx = 0;
	for (int i = 0; i <= K; i++) {
		dp[i] = 987654321;
	}
	for (int i = 0; i < N; i++) {
		int cost;
		cin >> cost;
		if (cost > 10000) {
			continue;
		}
		if (dp[cost] == 1)
			continue;
		dp[cost] = 1;
		money[idx++] = cost;
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < idx; j++) {
			if (i - money[j] <= 0)
				continue;
			dp[i] = min(dp[i], dp[i - money[j]] + 1);
		}
	}
	if (dp[K] == 987654321)
		cout << -1 << '\n';
	else 
		cout << dp[K] << '\n';
	return 0;
}