#include<iostream>

using namespace std;
int N, M;
int list[302][22];
int dp[302][22];
int ans[302][22];

int sol (int a, int c) {
	if (c > M)
		return 0;
	int &t = dp[a][c];
	if (t != -1)
		return t;
	t = 0;
	for (int i = 0; i <= a; i++) {
		int temp = list[i][c] + sol(a - i, c + 1);
		if (t < temp) {
			t = temp;
			ans[a][c] = i;
		}
	}
	return t;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			cin >> list[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(N, 1) << '\n';
	for (int i = 1; i <= M; i++) {
		cout << ans[N][i] << ' ';
		N -= ans[N][i];
	}
	cout << '\n';
	return 0;
}
