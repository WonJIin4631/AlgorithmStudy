#include<iostream>
using namespace std;
int map[1001][1001];
pair<int,int> dp[1001][1001];
int N, M;

int dx[] = { -1,0,1 };
int dy[] = { 1,1,1, };
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if(i != 0)
				dp[i][j].first = 987654321;
			else {
				dp[i][j].first = map[i][j];
			}
		}
	}
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cur = dp[i][j].first;
			for (int k = 0; k < 3; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx >= 0 && ny >= 0 && ny < N&&nx < M) {
					if (k == dp[i][j].second && i != 0) {
						//cout << i << ' '<<j << '\n';
						continue;
					}
					if (dp[ny][nx].first > cur + map[ny][nx]) {
						dp[ny][nx].first = cur + map[ny][nx];
						dp[ny][nx].second = k;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<< dp[i][j].first << ' ';
		}
		cout << '\n';
	}
	int ans = 987654321;
	for (int i = 0; i < M; i++) {
		if (ans > dp[N - 1][i].first)
			ans = dp[N - 1][i].first;
	}
	cout << ans << '\n';
}