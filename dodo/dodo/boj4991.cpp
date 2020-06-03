#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 987654321
struct Info {
	int x;
	int y;
};
struct mInfo {
	int x;
	int y;
	int cnt;
};
struct dest {
	int from;
	int to;
	int dist;
};
struct comp {
	bool operator() (dest a, dest b) {
		return a.dist > b.dist;
	}
};
bool cccc[11] = {0 };
int map[21][21];
int munzi_cnt;
bool visit[21][21];
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
Info munzi_pos[10];
bool munzi_ch[11];
int distMap[11][11];
int ans = INF;
void init() {
	munzi_cnt = 0;
	ans = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
			char c;
			cin >> c;
			if (c == '.') {
				map[i][j] = 0;
			}
			else if (c == '*') {
				munzi_cnt++;
				munzi_pos[munzi_cnt] = { j,i };
				map[i][j] = munzi_cnt;
			}
			else if (c == 'o') {
				map[i][j] = 0;
				munzi_pos[0] = { j,i };
			}
			else {
				map[i][j] = -1;
			}
		}
	}
	for (int i = 0; i <= munzi_cnt; i++) {
		for (int j = 0; j <= munzi_cnt; j++) {
			distMap[i][j] = INF;
		}


	}
}
bool isIn(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
void BFS(int x, int y, int idx) {
	queue<mInfo> q;
	q.push({ x,y ,0 });
	visit[y][x] = true;
	while (!q.empty()) {
		mInfo cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (isIn(nx, ny)) {
				if (!visit[ny][nx]) {
					if (map[ny][nx] == 0) {
						visit[ny][nx] = true;
						q.push({ nx,ny,cur.cnt + 1 });
					}
					else if (map[ny][nx] > 0) {
						int dd = map[ny][nx];
						visit[ny][nx] = true;
						munzi_ch[dd] = true;
						distMap[dd][idx] = distMap[idx][dd] = min(distMap[idx][dd], cur.cnt + 1);
						q.push({ nx,ny,cur.cnt + 1 });
					}
				}
			}
		}
	}
}
void DFS(int from,int dist,int cnt) {
	if (cnt == munzi_cnt) {
		ans = min(ans, dist);
		return;
	}
	if (ans <= dist)
		return;
	for (int i = 1; i <= munzi_cnt; i++) {
		if (cccc[i] == false) {
			cccc[i] = true;
			DFS(i, dist + distMap[from][i], cnt + 1);
			cccc[i] = false;
		}
	}
}
void solve() {
	init();
	for (int i = 0; i <= munzi_cnt; i++)
		munzi_ch[i] = false;
	BFS(munzi_pos[0].x, munzi_pos[0].y, 0);
	for (int i = 1; i <= munzi_cnt; i++) {
		if (munzi_ch[i]) {
			memset(visit, 0, sizeof(visit));
			BFS(munzi_pos[i].x, munzi_pos[i].y, i);
		}
		else {
			ans = -1;
			break;
		}
	}
	DFS(0, 0, 0);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> M >> N;
		if (N == 0 && M == 0)
			break;
		solve();
	}

	return 0;
}
