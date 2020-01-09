#include<iostream>
#include<queue>
#include<math.h>
#include<string.h>
using namespace std;

int map[21][21];
int visit[21][21];
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
/*
매칸 마다 운영영역 크기 1부터 시작해서 값이 0보다 작을때까지 계산
운영영역은 bfs로 영역크기 넓히기
손해를 보지않고 서비스 제공할수 있는 집의 수
*/

void BFS(int cy, int cx) {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(cx, cy));
	int size = 0;
	int level = 1;
	int cnt = 0;
	visit[cy][cx] = 1;
	if (map[cy][cx] == 1)
		cnt = 1;
	while (!q.empty()) {
		size = level*level + (level - 1)*(level - 1);
		int qsize = q.size();
		if (cnt*M - size >= 0) {
			ans = max(ans, cnt);
		}
		if (level > N) {
			break;
		}
		for (int k = 0; k < qsize; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (visit[ny][nx] == 0) {
						if (map[ny][nx] == 1) 
							cnt++;
						visit[ny][nx] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		level++;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			BFS(i, j);
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		solve();
		cout << '#' << t << ' ' << ans << '\n';
		ans = 0;
	}
	return 0;
}