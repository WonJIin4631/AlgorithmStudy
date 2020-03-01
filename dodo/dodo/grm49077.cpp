#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int maxAns = 0;
int cntAns = 0;
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char map[1002][1002];
int visit[1002][1002] = { 0 };
typedef pair<int, int> pii;
int BFS(int x, int y) {
	queue<pii> q;
	q.push(pii(x, y));
	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < M) {
				if (map[ny][nx] == '#') {
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						cnt++;
						q.push(pii(nx, ny));
					}
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '#') {
				if (visit[i][j] == 0) {
					cntAns++;
					visit[i][j] = 1;
					int sz = BFS(j, i);
					maxAns = max(maxAns, sz);
				}
			}
		}
	}
	cout << cntAns << '\n' << maxAns << '\n';
	return 0;
}