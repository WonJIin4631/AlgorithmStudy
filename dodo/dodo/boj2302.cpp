#include <iostream>
using namespace std;

int dp[51] = { 0 };

int main(){
	
	int N;
	int M;
	int ans = 1;

	cin >> N;
	cin >> M;
	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		dp[num] = -1;
	}

	dp[0] = -1;
	dp[N + 1] = -1;

	for (int i = 1; i <= N; ++i) {
		if (dp[i] == -1) {
			continue;
		}
		if (dp[i - 1] == -1) {
			dp[i] = 1;
			continue;
		}
		if (i > 1 && dp[i - 2] == -1) {
			dp[i] = 2;
			continue;
		}
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 1; i <= N + 1; ++i) {
		if (dp[i] == -1 && dp[i - 1] != -1) {
			ans *= dp[i - 1];
		}
	}
	cout << ans << '\n';
	return 0;
}