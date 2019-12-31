#include<iostream>
#include<algorithm>

using namespace std;
int map[1002][1002];
int dp[3][1002][1002];
int N, M;

int dx[] = { -1,0,1 };

int ans = 987654321;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int k = 0; k < 3; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				dp[k][i][j] = 987654321;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		dp[0][1][i] = dp[1][1][i] = dp[2][1][i] = map[1][i];
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M; j++) {
			for (int p_dir = 0; p_dir < 3; p_dir++) {
				for (int n_dir = 0; n_dir < 3; n_dir++) {
					if (p_dir == n_dir)
						continue;
					int nm = j + dx[n_dir];
					dp[n_dir][i + 1][nm] = min(dp[p_dir][i][j] + map[i + 1][nm], dp[n_dir][i + 1][nm]);
				}
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 3; j++) {
			ans = min(ans, dp[j][N][i]);
		}
	}
	cout << ans <<'\n';

	return 0;
}