#include<iostream>
using namespace std;
/*
점화식 i번 개수 = (i-1)번 개수 + (i-2)번 개수
*/

int main() {
	int N;
	cin >> N;
	long long dp[92];
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N] << '\n';
}