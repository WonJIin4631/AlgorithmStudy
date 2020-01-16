#include<iostream>
#include<vector>
using namespace std;

int coin[100 + 1];
int	dp[10000 + 1] = { 0, };
int n, k;
int ans = 0;


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	cout << dp[k];
}