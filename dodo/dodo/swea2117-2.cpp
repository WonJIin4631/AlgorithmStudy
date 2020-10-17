#include <iostream>
#include <queue>
#include <algorithm>
#include<cstring>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int T, N, M;
bool map[21][21] = { 0 };
bool visit[21][21] = { 0 };

struct Info {
	int x;
	int y;
};
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
int checkCost(int x, int y) {
	queue<Info> q;
	q.push({ x,y });
	visit[y][x] = true;
	int cnt = 0;
	int width = 1;
	int val = 0;
	while (!q.empty()) {
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			Info cur = q.front();
			q.pop();
			if (map[cur.y][cur.x])
				cnt++;
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny)) {
					if (visit[ny][nx] == false) {
						visit[ny][nx] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		int cost = (M*cnt) - (width*width + (width - 1)*(width - 1));
		if(cost>=0)
			val = max(val,cnt);
		width++;
	}
	memset(visit, false, sizeof(visit));
	return val;
}
int solve() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, checkCost(j, i));
		}
	}
	return ans;
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cout << '#' << tc << ' ' << solve() << '\n';
	}
	return 0;
}