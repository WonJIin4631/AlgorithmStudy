#include<iostream>
#include<algorithm>
using namespace std;

int map[1002] = { 0 };
int dp[1002] = { 0 };
int N;
int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
		dp[i] = -1;
	}
	dp[1] = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] != -1) {
			int moveCan = map[i];
			for (int j = i + 1; j <= i + moveCan; j++) {
				if (j > N)
					break;
				if (dp[j] == -1) {
					dp[j] = dp[i] + 1;
				}
				else {
					dp[j] = min(dp[j], dp[i] + 1);
				}
			}
		}
	}
	if (dp[N] == -1)
		cout << -1 << '\n';
	else
		cout << dp[N] << '\n';
	return 0;
}