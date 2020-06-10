#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001] = { 0 };
int dx[] = { -1,-1,0 };
int dy[] = { 0,-1,-1 };
bool isIn(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	dp[N-1][M-1] = map[N-1][M-1];
	for (int i = N-1; i >=0 ; i--) {
		for (int j = M-1; j >=0; j--) {
			for (int d = 0; d < 3; d++) {
				int nx = j + dx[d];
				int ny = i + dy[d];
				if (isIn(nx, ny)) {
					dp[ny][nx] = max(dp[ny][nx], dp[i][j] + map[ny][nx]);
				}
			}
		}
	}
	cout << dp[0][0] << '\n';
	return 0;
}