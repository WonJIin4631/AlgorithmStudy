#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct Info {
	int x;
	int y;
};
int N, M;
bool light[102][102] = { 0 };
bool visit[102][102] = { 0 };
vector<Info> map[102][102];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool isIn(int x, int y) {
	return x >= 1 && x <= N&&y >= 1 && y <= N;
}
int lightOn(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < map[y][x].size(); i++) {
		int cx = map[y][x][i].x;
		int cy = map[y][x][i].y;
		bool flag = false;
		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (isIn(nx, ny)) {
				if (light[ny][nx]) {
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			if (!light[cy][cx])
				cnt++;
			light[cy][cx] = true;
		}
	}
	return cnt;
}
void solve() {
	int ans = 0;
	while (true) {
		bool flag = false;
		visit[1][1] = true;
		light[1][1] = true;
		memset(visit, 0, sizeof(visit));
		queue<Info> q;
		q.push({1, 1});
		while (!q.empty()){
			Info cur = q.front();
			q.pop();
			int x = cur.x;
			int y = cur.y;
			if (map[y][x].size() != 0) {
				for (int i = 0; i < map[y][x].size(); i++) {
					int nx = map[y][x][i].x;
					int ny = map[y][x][i].y;
					light[ny][nx] = true;
				}
				map[y][x].clear();
				flag = true;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (isIn(nx, ny)) {
					if (light[ny][nx]) {
						if (!visit[ny][nx]) {
							visit[ny][nx] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		if (!flag)
			break;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (light[i][j])
				ans++;
		}
	}
	cout << ans << '\n';
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		map[y][x].push_back({ a,b });
	}
}
int main() {
	init();
	solve();
	return 0;
}