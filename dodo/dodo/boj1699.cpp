#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001] = { 0 };
int N;
int main() {
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 987654321;
		for (int j = 1; j <= i; j++) {
			if (i < j*j)
				break;
			if (i == j*j)
				dp[i] = 1;
			if (i - j*j >= 0)
				dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}