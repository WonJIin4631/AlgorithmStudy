#include<iostream>
using namespace std;
/*
점화식 i의 값은 ((i-2)*2+(i-1))
*/
int main() {
	long long dp[1001];
	int N;
	dp[1] = 1;
	dp[2] = 3;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = ((dp[i - 2] * 2) + dp[i - 1]) % 10007;
	}

	cout << dp[N];
	return 0;
}