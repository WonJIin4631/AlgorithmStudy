#include<iostream>
#include<algorithm>
using namespace std;

int N;
int card[1002];
int dp[1002] = { 0 };
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i], card[i]);
		for (int j = 1; j <=i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}