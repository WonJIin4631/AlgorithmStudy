#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


struct Info{
	int x;
	int y;
};
int R, C;
char map[51][51];
bool visit[51][51];
int timeMap[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<Info> q;
Info dochi;
Info biber;
bool Isin(int x, int y) {
	return x >= 0 && x < C&&y >= 0 && y < R;
}
void water_Move() {
	int time = 0;
	while (!q.empty()){
		int qsz = q.size();
		for (int tt = 0; tt < qsz; tt++) {
			Info cur = q.front();
			q.pop();
			timeMap[cur.y][cur.x] = time;
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (Isin(nx, ny)) {
					if (visit[ny][nx] == false) {
						if (map[ny][nx] != 'X'&&map[ny][nx] != 'D') {
							visit[ny][nx] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		time++;
	}
}
void dochi_Move() {
	memset(visit, 0, sizeof(visit));
	q.push(dochi);
	visit[dochi.y][dochi.x] = true;
	int time = 0;
	bool flag = false;
	while (!q.empty()){
		int qsz = q.size();
		for (int tt = 0; tt < qsz; tt++) {
			Info cur = q.front();
			q.pop();
			if (biber.x == cur.x&&biber.y == cur.y) {
				flag = true;
				break;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (Isin(nx, ny)) {
					if (visit[ny][nx] == false) {
						if (map[ny][nx] == '.' || map[ny][nx] == 'D') {
							if (timeMap[ny][nx] > time+1) {
								visit[ny][nx] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}
		if (flag)
			break;
		time++;
	}
	if (flag)
		cout << time << '\n';
	else
		cout << "KAKTUS" << '\n';
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			timeMap[i][j] = 987654321;
			if (map[i][j] == '*') {
				visit[i][j] = true;
				q.push({ j,i });
			}
			else if (map[i][j] == 'S') {
				dochi.y = i;
				dochi.x = j;
			}
			else if (map[i][j] == 'D') {
				biber.y = i;
				biber.x = j;
			}
		}
	}
	water_Move();
	dochi_Move();
	return 0;
}