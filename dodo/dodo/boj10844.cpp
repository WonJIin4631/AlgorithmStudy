#include<iostream>
using namespace std;

int N;
long long dp[101][11] = { 0 };

int main() {
	cin >> N;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	long long sum = 0;
	for (int i = 0; i <=9; i++) {
		sum += dp[N][i];
		sum %= 1000000000;
	}
	cout << sum << '\n';
	return 0;

}