#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Info {
	int x;
	int y;
	int st;
};
char block[7] = { '|','-','+','1','2','3','4' };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, M;
char map[26][26];
int visit[26][26] = { 0 };
Info st_pos, end_pos;
bool ans = false;
bool isIn(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
int checkBlock(char c, int dir) {
	if (c == '|') {
		if (dir == 0 || dir == 1) {
			return dir;
		}
	}
	else if (c == '-') {
		if (dir == 2 || dir == 3) {
			return dir;
		}
	}
	else if (c == '+') {
		if (dir == 0 || dir == 1 || dir == 2 || dir == 3) {
			return dir;
		}
	}
	else if (c == '1') {
		if (dir == 2)
			return 1;
		if (dir == 0)
			return 3;
	}
	else if (c == '2') {
		if (dir == 1)
			return 3;
		if (dir = 2)
			return 0;
	}
	else if (c == '3') {
		if (dir == 1)
			return 2;
		if (dir == 3)
			return 0;
	}
	else if (c == '4') {
		if (dir == 3)
			return 1;
		if (dir == 0)
			return 2;

	}
	return -1;
}
bool move() {
	visit[st_pos.y][st_pos.x] = 1;
	queue<Info> q;
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int nx = st_pos.x + dx[i];
		int ny = st_pos.y + dy[i];
		if (isIn(nx, ny)) {
			int temp = checkBlock(map[ny][nx], i);
			if (temp == -1)
				continue;
			visit[ny][nx] = 1;
			q.push({ nx, ny, temp });
		}
	}
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		int nx = cur.x + dx[cur.st];
		int ny = cur.y + dy[cur.st];
		if (map[ny][nx] == 'Z') {
			flag = true;
			continue;
		}

		if (isIn(nx, ny)) {
			if (map[ny][nx] == '.') {
				continue;
			}
			else if (map[ny][nx] == '+') {
				if (visit[ny][nx] < 2) {
					int cc = checkBlock(map[ny][nx], cur.st);
					if (cc != -1) {
						visit[ny][nx] += 1;
						q.push({ nx,ny,cc });
					}
				}
			}
			else {
				if (visit[ny][nx] == 0) {
					int cc = checkBlock(map[ny][nx], cur.st);

					if (cc != -1) {
						visit[ny][nx] += 1;
						q.push({ nx,ny,cc });
					}
				}
			}
		}
	}
	if (flag) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != '.'&&map[i][j]!='M'&&map[i][j]!='Z') {
					if (visit[i][j] == 0) {
						return false;
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	return flag;
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.') {
				for (int t = 0; t < 7; t++) {
					if (ans)
						continue;
					map[i][j] = block[t];
					if (move()) {
						ans = true;
						cout << i + 1 << ' ' << j + 1 << ' ' << block[t];
					}
					map[i][j] = '.';
				}
			}
		}
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M')
				st_pos = { j,i,1 };
			else if (map[i][j] == 'Z')
				end_pos = { j,i,1 };
		}
	}
	solve();
	return 0;
}