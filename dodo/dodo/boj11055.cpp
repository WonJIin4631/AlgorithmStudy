#include<iostream>
#include<algorithm>
using namespace std;

int N;
int numList[1001] = { 0 };
int dp[1001] = { 0 };
int ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numList[i];
	dp[0] = numList[0];
	//ans = dp[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (numList[i] > numList[j]) {
				dp[i] = max(dp[i], dp[j] + numList[i]);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans << '\n';
	return 0;
}