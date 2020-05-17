#include<iostream>
using namespace std;

int dp[31] = { 0 };
int N;

int main() {
	cin >> N;
	dp[0] = 1;
	for (int i = 2; i <= N; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			if (j == 2) {
				dp[i] = 3 * dp[i - 2];
			}
			else {
				dp[i] += dp[i - j] * 2;
			}
		}
	}
	cout << dp[N] << '\n';
	return 0;
}