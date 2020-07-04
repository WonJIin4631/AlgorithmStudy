#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define INF 987654321
struct Info {
	int x;
	int y;
	int f;
};
int N, M, F;
bool blockMap[22][22];
bool visit[22][22] = { 0 };
bool check[22] = { 0 };
int st_map[22][22];
Info st_pos[22];
int dist_map[22][22];
vector<int> end_map[22][22];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
bool isIn(int x, int y) {
	return x >= 1 && x <= N&&y >= 1 && y <= N;
}
void solve(int f) {
	int cnt = 0;
	int from= 0;
	bool flag = false;
	while (true){
		if (cnt == M) {
			ans = f;
			break;
		}
		if (f < 0) {
			flag = true;
			break;
		}
		int minDist = INF;
		int minIdx=0;
		for (int i = 1; i <= M; i++) {
			if (!check[i]) {
				if (dist_map[from][i] < minDist) {
					minDist = dist_map[from][i];
					minIdx = i;
				}
				else if (dist_map[from][i] == minDist) {
					if (st_pos[minIdx].y > st_pos[i].y) {
						minIdx = i;
					}
					else if (st_pos[minIdx].y == st_pos[i].y) {
						if (st_pos[minIdx].x > st_pos[i].x) {
							minIdx = i;
						}
					}
				}
			}
		}
		if (f - dist_map[from][minIdx] < 0) {
			flag = true;
			break;
		}
		f -= dist_map[from][minIdx];
		if (f - dist_map[from][minIdx] < 0) {
			flag = true;
			break;
		}
		f += dist_map[minIdx][minIdx];
		from = minIdx;
		check[minIdx] = true;
		cnt++;
	}
	if (!flag)
		ans = f;
}
void get_Dist(int x, int y) {
	queue<Info> q;
	Info c = { x,y,0 };
	visit[y][x] = true;

	int cNum = st_map[y][x];
	for (int i = 0; i < end_map[y][x].size(); i++) {
		dist_map[end_map[y][x][i]][cNum] = 0;
	}
	q.push(c);
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (isIn(nx, ny)) {
				//장애물 없을때
				if (!blockMap[ny][nx]) {
					if (!visit[ny][nx]) {
						if (end_map[ny][nx].size() != 0) {
							for (int i = 0; i < end_map[ny][nx].size(); i++) {
								int nNum = end_map[ny][nx][i];
								if (cNum == nNum) {
									dist_map[cNum][cNum] = cur.f + 1;
								}
								else {
									dist_map[nNum][cNum] = cur.f + 1;
								}
							}
						}
						visit[ny][nx] = true;
						q.push({ nx, ny, cur.f + 1 });
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}
void st_DIst(int x, int y) {
	queue<Info> q;
	Info c = { x,y,0 };
	visit[y][x] = true;
	q.push(c);
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (isIn(nx, ny)) {
				if (!blockMap[ny][nx]) {
					if (!visit[ny][nx]) {
						if (st_map[ny][nx] != 0) {
							int nNum = st_map[ny][nx];
							dist_map[0][nNum] = cur.f + 1;
						}
						visit[ny][nx] = true;
						q.push({ nx,ny,cur.f + 1 });
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}
int main() {
	cin >> N >> M >> F;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> blockMap[i][j];
		}
	}
	int x; int y;
	cin >> y >> x;
	st_pos[0].x = st_pos[0].y= 20;

	for (int i = 1; i <= M; i++) {
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		st_map[sy][sx] = i;
		st_pos[i].x = sx;
		st_pos[i].y = sy;
		end_map[ey][ex].push_back(i);
	}
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			dist_map[i][j] = INF;
		}
	}
	st_DIst(x, y);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (st_map[i][j] != 0) {
				get_Dist(j, i);
			}
		}
	}
	solve(F);
	if (ans == INF)
		ans = -1;
	cout << ans << '\n';
	return 0;
}