#include <iostream>
#include<cstring>
using namespace std;


int n;
int list[103];
long long dp[110][22];

long long solve(int i, int j) {
	if (i < 0 || j < 0 || j > 20) 
		return 0;
	if (i == 0 && j == list[0]) 
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = solve(i - 1, j - list[i]) + solve(i - 1, j + list[i]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(n - 2, list[n - 1]) << '\n';
	return 0;
}