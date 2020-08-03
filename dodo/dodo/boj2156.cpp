#include<iostream>
#include<algorithm>
using namespace std;

int N;
long long podoju[10001];
long long dp[10001] = { 0 };
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> podoju[i];
	}
	dp[1] = podoju[1];
	if (N > 1)
		dp[2] = podoju[1] + podoju[2];
	if (N > 2) {
		for (int i = 3; i <= N; i++) {
			long long temp = max(dp[i - 1], dp[i - 2] + podoju[i]);
			dp[i] = max(temp, dp[i - 3] + podoju[i - 1] + podoju[i]);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}