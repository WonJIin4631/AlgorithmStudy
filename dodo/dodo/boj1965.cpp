#include<iostream>
#include<algorithm>
using namespace std;

int box[1002] = { 0 };
int dp[1002] = { 0 };
int ans = 0;
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> box[i];
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans << '\n';
}