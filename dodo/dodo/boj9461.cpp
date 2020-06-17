#include<iostream>
using namespace std;

int T;
int t;
int ans = 0;
long long dp[101] = { 0 };

int main() {

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	cin >> T;
	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	for (int i = 0; i < T; i++) {
		cin >> t;
		cout << dp[t] << '\n';
	}
	return 0;
}