#include<iostream>
using namespace std;
typedef struct node {
	int s;
	int d;
	int z;
};
node map[101][101];
int R, C, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int ans = 0;

// 갈려는 칸 R또는 C * 2-2 이면 제자리 
void move_shark() {
	node cpymap[101][101] = { 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].z != 0) {
				//위아래
				int dir = map[i][j].d;
				if (dir == 1 || dir == 2) {
					int speed = map[i][j].s;
					speed =speed % (R * 2 - 2);
					
					int ny;
					if (i + speed*dy[dir-1] < 0) {
						ny =  speed - i;
						map[i][j].d = 2;
						if (ny >= R - 1) {
							ny = R - 1 - (ny - (R - 1));
							map[i][j].d = 1;
						}
						
					}
					else if (i + speed*dy[dir - 1] >= R) {
						ny = R - 1 - (speed - (R - 1 - i));
						map[i][j].d = 1;
						if (ny <= 0) {
							ny *= -1;
							map[i][j].d = 2;
						}
					}
					else {
						ny =i+ speed*dy[dir - 1];
						if (ny == 0)
							map[i][j].d = 2;
						if (ny == R - 1)
							map[i][j].d = 1;
					}
					if (cpymap[ny][j].z == 0) {
						cpymap[ny][j].s = map[i][j].s;
						cpymap[ny][j].d = map[i][j].d;
						cpymap[ny][j].z = map[i][j].z;
					}
					else {
						if (cpymap[ny][j].z < map[i][j].z) {
							cpymap[ny][j].s = map[i][j].s;
							cpymap[ny][j].d = map[i][j].d;
							cpymap[ny][j].z = map[i][j].z;
						}
					}
				}
				//좌우
				else {
					int speed = map[i][j].s;
					speed = speed % (C * 2 - 2);
					int nx;
					if (j + speed*dx[dir - 1] < 0) {
						nx = speed - j;
						map[i][j].d = 3;
						if (nx >= C - 1) {
							nx = C - 1 - (nx - (C - 1));
							map[i][j].d = 4;
						}
					}
					else if (j + speed*dx[dir - 1] >= C) {
						nx = C - 1 - (speed - (C - 1 - j));
						map[i][j].d = 4;
						if (nx <= 0) {
							nx *= -1;
							map[i][j].d = 3;
						}
					}
					else {
						nx =j+ speed*dx[dir - 1];
						if (nx == 0)
							map[i][j].d = 3;
						if (nx == 0)
							map[i][j].d = 4;
					}
					if (cpymap[i][nx].z == 0) {
						cpymap[i][nx].s = map[i][j].s;
						cpymap[i][nx].d = map[i][j].d;
						cpymap[i][nx].z = map[i][j].z;
					}
					else {
						if (cpymap[i][nx].z < map[i][j].z) {
							cpymap[i][nx].s = map[i][j].s;
							cpymap[i][nx].d = map[i][j].d;
							cpymap[i][nx].z = map[i][j].z;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j].d = cpymap[i][j].d;
			map[i][j].s = cpymap[i][j].s;
			map[i][j].z = cpymap[i][j].z;
		}
	}
}
void solve() {
	for (int k = 0; k < C; k++) {
		for (int i = 0; i < R; i++) {
			if (map[i][k].z != 0) {
				ans += map[i][k].z;
				map[i][k].z = 0;
				break;
			}
		}
		move_shark();
	}
}
int main() {
	cin >> R >> C >> M;
	if (M == 0)
		cout << 0 << '\n';
	else {
		for (int i = 0; i < M; i++) {
			int r, c, s, d, z;
			cin >> r >> c >> s >> d >> z;
			map[r - 1][c - 1].s = s;
			map[r - 1][c - 1].d = d;
			map[r - 1][c - 1].z = z;
		}

		solve();
		cout << ans << '\n';
	}
	return 0;
}