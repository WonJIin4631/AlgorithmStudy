#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define INF 987654321
struct Info {
	int x;
	int y;
};
Info node[4];
int N, M;
bool visit[102][102];
Info map[102][102];
int ans = INF;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool isin(int x, int y) {
	return x >= 0 && x <= M&&y >= 0 && y <= N;
}
void getLine(char c) {
	if (c == 'A') {
		int x = node[1].x;
		int y = node[1].y;
		visit[y][x] = true;
		while (true) {
			if (x == node[0].x&&y == node[0].y) {
				break;
			}
			int nx = map[y][x].x;
			int ny = map[y][x].y;
			x = nx;
			y = ny;
			visit[y][x] = true;
		}
	}
	else {
		int x = node[3].x;
		int y = node[3].y;
		visit[y][x] = true;
		while (true) {
			if (x == node[2].x&&y == node[2].y) {
				break;
			}
			int nx = map[y][x].x;
			int ny = map[y][x].y;
			x = nx;
			y = ny;
			visit[y][x] = true;
		}
	}
}
int BFS(char c) {
	queue<Info> q;
	if (c == 'A') {
		q.push(node[0]);
		visit[node[0].y][node[0].x] = true;
	}
	else if (c == 'B') {
		q.push(node[2]);
		visit[node[2].y][node[2].x] = true;
	}
	int time = 0;
	bool flag = false;
	while (!q.empty()) {
		int qsz = q.size();
		for (int tt = 0; tt < qsz; tt++) {
			Info cur = q.front();
			q.pop();
			if (c == 'A') {
				if (flag)
					continue;
				if (cur.x == node[1].x &&cur.y == node[1].y) {
					flag = true;
					continue;
				}
			}
			if (c == 'B') {
				if (flag)
					continue;
				if (cur.x == node[3].x &&cur.y == node[3].y) {
					flag = true;
					continue;
				}
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (c == 'A') {
					if ((nx == node[2].x&&ny == node[2].y)|| nx == node[3].x&&ny == node[3].y)
						continue;
				}
				else if (c == 'B') {
					if ((nx == node[0].x&&ny == node[0].y) || nx == node[1].x&&ny == node[1].y)
						continue;
				}
				if (isin(nx, ny)) {
					if (visit[ny][nx] == false) {
						visit[ny][nx] = true;
						q.push({nx,ny});
						map[ny][nx] = { cur.x,cur.y };
					}
				}
			}

		}
		if (!flag)
			time++;
	}
	if (!flag)
		time = INF;
	return time;
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < 4; i++) {
		cin >> node[i].x >> node[i].y;
	}
	int ta, tb;
	ta = BFS('A');
	memset(visit, 0, sizeof(visit));
	getLine('A');
	tb= BFS('B');
	ans = min(ans, ta + tb);
	memset(visit, 0, sizeof(visit));
	tb= BFS('B');
	memset(visit, 0, sizeof(visit));
	getLine('B');
	ta=BFS('A');
	ans = min(ans, ta + tb);
	if (ans == INF)
		cout << "IMPOSSIBLE" << '\n';
	else
		cout << ans << '\n';
	return 0;
}