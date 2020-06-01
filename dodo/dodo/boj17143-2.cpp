#include<iostream>
using namespace std;

int R, C, M;
int dx[] = { 0,0,0,1,-1 };
int dy[] = { 0,-1,1,0,0 };
bool check[10002];
int map[102][102];
int ans = 0;
//s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
typedef struct info{
	int r, c, s, d, z;
};
info shark[10002];
int chg_dir(int d) {
	if (d == 1)
		return 2;
	else if (d == 2)
		return 1;
	else if (d == 3)
		return 4;
	else if (d == 4)
		return 3;
}
void move() {
	int t_map[102][102] = { 0 };
	for (int i = 1; i <= M; i++) {
		//cout << i << '\n';
		if (check[i] == false) {
			//상하
			if (shark[i].d == 1 || shark[i].d == 2) {
				if (shark[i].s >= ((R * 2) - 2)) {
					shark[i].s %= ((R * 2) - 2);
				}
				int ss = shark[i].s;
				int d = shark[i].d;
				int r = shark[i].r;
				int c = shark[i].c;
				int z = shark[i].z;
				//상어이동
				for (int j = 0; j < ss; j++) {
					if (r + dy[d] > R) {
						d = chg_dir(d);
					}
					else if (r + dy[d] < 1) {
						d = chg_dir(d);
					}
					r += dy[d];
				}
				if (t_map[r][c] != 0) {
					if (shark[t_map[r][c]].z  < z) {
						check[t_map[r][c]] = true;
						t_map[r][c] = i;
						shark[i] = { r, c, ss, d, z };
					}
					else {
						check[i] = true;
					}
				}
				else {
					shark[i] = { r, c, ss, d, z };
					t_map[r][c] = i;
				}
			}
			//좌우
			else if(shark[i].d == 3 || shark[i].d == 4) {
				if (shark[i].s >= (C* 2) - 2) {
					shark[i].s %= ((C * 2) - 2);
				}
				int ss = shark[i].s;
				int d = shark[i].d;
				int r = shark[i].r;
				int c = shark[i].c;
				int z = shark[i].z;
				//상어이동
				for (int j = 0; j < ss; j++) {
					if (c + dx[d] > C) {
						d = chg_dir(d);
					}
					else if (c + dx[d] < 1) {
						d = chg_dir(d);
					}
					c += dx[d];
				}
				if (t_map[r][c] != 0) {
					if (shark[t_map[r][c]].z < z) {
						check[t_map[r][c]] = true;
						t_map[r][c] = i;
						shark[i] = { r, c, ss, d, z };
					}
					else {
						check[i] = true;
					}
				}
				else {
					shark[i] = { r, c, ss, d, z };
					t_map[r][c] = i;
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = t_map[i][j];
		}
	}
}
int main() {
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark[i] = { r, c, s, d, z };
		map[r][c]=i;
	}
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (map[j][i] != 0) {
				int cur = map[j][i];
				check[cur] = true;
				ans += shark[cur].z;
				map[j][i] = 0;
				break;
			}
		}
		move();
	}
	cout << ans << '\n';
	return 0;
}