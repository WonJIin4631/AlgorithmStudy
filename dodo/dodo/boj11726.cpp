#include<iostream>
using namespace std;


int dp[1001];
int N;
int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	if (N <= 2) {
		cout << N << '\n';
	}
	else {
		cout << dp[N] << '\n';
	}
}