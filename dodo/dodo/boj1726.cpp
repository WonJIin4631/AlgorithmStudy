#include<iostream>
#include<queue>
using namespace std;

int map[102][102] = { 0 };
int visit[5][102][102];
int dx[] = { 0, 1,-1,0,0 };
int dy[] = { 0, 0,0,1,-1 };
int N, M;

struct info {
	int x;
	int y;
	int dir;
};
info stP;
info endP;
int get_dir(int d, char c) {
	if (c == 'L') {
		if (d == 1)
			return 4;
		else if (d == 2)
			return 3;
		else if (d == 3)
			return 1;
		else
			return 2;
	}
	else {
		if (d == 1)
			return 3;
		else if (d == 2)
			return 4;
		else if (d == 3)
			return 2;
		else
			return 1;
	}
}
int solve() {
	queue<info> q;
	q.push(stP);
	visit[stP.dir][stP.y][stP.x] = 1;
	int time = 0;
	while (!q.empty()) {
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int y = q.front().y;
			int x = q.front().x;
			int d = q.front().dir;
			q.pop();
			if (y == endP.y&&x == endP.x&&endP.dir == d) {
				return time;
			}
			int nx = x;
			int ny = y;
			for (int j = 0; j < 3; j++) {
				nx += dx[d];
				ny += dy[d];
				if (visit[d][ny][nx] == 0) {
					if (ny >= 1 && ny <= N&&nx >= 1 && nx <= M) {
						if (map[ny][nx] == 0) {
							visit[d][ny][nx] = 1;
							q.push(info{ nx,ny,d });
						}
						else
							break;
					}
				}
			}
			int l, r;
			l = get_dir(d, 'L');
			r = get_dir(d, 'R');
			if (visit[l][y][x] == 0) {
				visit[l][y][x] = 1;
				q.push(info{ x,y,l });
			}
			if (visit[r][y][x] == 0) {
				visit[r][y][x] = 1;
				q.push(info{ x,y,r });
			}
		}
		time++;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> stP.y >> stP.x >> stP.dir;
	cin >> endP.y >> endP.x >> endP.dir;
	cout << solve() << '\n';
	return 0;
}