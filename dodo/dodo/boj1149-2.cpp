#include<iostream>
#include<algorithm>
using namespace std;


int dp[1001][3];
int arr[1001][3];
int ans = 987654321;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			if (i == 0)
				dp[0][j] = arr[0][j];
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = arr[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
			}
			else if (j == 1) {
				dp[i][j] = arr[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
			}
			else {
				dp[i][j] = arr[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		ans = min(dp[N - 1][i], ans);
	}
	cout << ans << '\n';
	return 0;
}