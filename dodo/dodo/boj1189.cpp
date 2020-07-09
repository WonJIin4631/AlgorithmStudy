#include<iostream>
using namespace std;

int N, M, K;
char map[6][6];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool visit[6][6] = { 0 };
int ans = 0;
bool isIn(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
void DFS(int x, int y, int cnt) {
	if (x == M - 1 && y == 0) {
		if(cnt==K)
			ans++;
		return;
	}
	if (K == cnt)
		return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isIn(nx, ny)) {
			if (map[ny][nx] == '.') {
				if (visit[ny][nx] == false) {
					visit[ny][nx] = true;
					DFS(nx, ny, cnt + 1);
					visit[ny][nx] = false;
				}
			}
		}
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	visit[N - 1][0] = true;
	DFS(0, N - 1, 1);

	cout << ans << '\n';
	return 0;
}