#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int N, M, K;
int map[51][51] = { 0 };
int visit[51][51] = { 0 };
queue<pair<int, int>>q;
int ans = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void BFS(int x, int y) {
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (visit[ny][nx] == 0 && map[ny][nx] == 1) {
					visit[ny][nx] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					if (visit[i][j] == 0) {
						BFS(j, i);
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
		ans = 0;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
	}
	return 0;
}