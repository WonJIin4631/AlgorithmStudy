#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Info {
	int x;
	int y;
};

int R, C, T;
int map[51][51] = { 0 };
int cpymap[51][51] = { 0 };
Info cleaner[2];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
bool isIn(int x, int y) {
	return x >= 0 && x < C&&y >= 0 && y < R;
}
void init() {
	cin >> R >> C >> T;
	int idx = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				cleaner[idx++] = { j,i };
		}
	}
}
void spreadMunzi() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != 0 && map[i][j] != -1) {
				int checkdir = 0;
				for (int d = 0; d < 4; d++) {
					int nx = j + dx[d];
					int ny = i + dy[d];
					if (isIn(nx, ny) && (map[ny][nx] != -1)) {
						cpymap[ny][nx] += map[i][j] / 5;
						checkdir++;
					}
				}
				cpymap[i][j] += map[i][j] - (map[i][j] / 5)*checkdir;
			}
		}
	}
}
void moveMunzi() {
	deque<int> dq1;
	deque<int> dq2;
	for (int i = cleaner[0].x + 1; i < C; i++) {
		dq1.push_back(cpymap[cleaner[0].y][i]);
		dq2.push_back(cpymap[cleaner[1].y][i]);
	}
	for (int i = cleaner[0].y - 1; i > 0; i--)
		dq1.push_back(cpymap[i][C - 1]);
	for (int i = cleaner[1].y + 1; i < R - 1; i++)
		dq2.push_back(cpymap[i][C - 1]);

	for (int i = C - 1; i >= 0; i--) {
		dq1.push_back(cpymap[0][i]);
		dq2.push_back(cpymap[R - 1][i]);
	}
	for (int i = 1; i < cleaner[0].y; i++)
		dq1.push_back(cpymap[i][0]);
	for (int i = R - 2; i > cleaner[1].y; i--)
		dq2.push_back(cpymap[i][0]);
	dq1.pop_back();	dq1.push_front(0);
	dq2.pop_back(); dq2.push_front(0);
	for (int i = cleaner[0].x + 1; i < C; i++) {
		cpymap[cleaner[0].y][i] = dq1.front(); dq1.pop_front();
		cpymap[cleaner[1].y][i] = dq2.front(); dq2.pop_front();
	}
	for (int i = cleaner[0].y - 1; i > 0; i--) {
		cpymap[i][C - 1] = dq1.front(); dq1.pop_front();
	}
	for (int i = cleaner[1].y + 1; i < R - 1; i++) {
		cpymap[i][C - 1] = dq2.front(); dq2.pop_front();
	}

	for (int i = C - 1; i >= 0; i--) {
		cpymap[0][i] = dq1.front(); dq1.pop_front();
		cpymap[R - 1][i] = dq2.front(); dq2.pop_front();
	}
	for (int i = 1; i < cleaner[0].y; i++) {
		cpymap[i][0] = dq1.front(); dq1.pop_front();
	}

	for (int i = R - 2; i > cleaner[1].y; i--) {
		cpymap[i][0] = dq2.front(); dq2.pop_front();
	}
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1)
				continue;
			map[i][j] = cpymap[i][j];
			cpymap[i][j] = 0;
			ans += map[i][j];
		}
}
int main() {
	init();
	while (T--) {
		ans = 0;
		spreadMunzi();
		moveMunzi();
	}
	cout << ans << '\n';
	return 0;
}