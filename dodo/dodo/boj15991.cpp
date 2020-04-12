#include<iostream>
using namespace std;
#define MAX 1000000009
long long dp[100001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;

	for (int i = 6; i <= 100000; i++) {
		if (i % 2 == 0) {
			dp[i] = (dp[i - 1] + dp[i - 3] + dp[i - 5])%MAX;
		}
		else {
			dp[i] = dp[i - 1]%MAX;
		}
	}
	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}