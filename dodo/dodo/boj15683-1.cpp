#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int map[10][10];
bool visit[10][10];
int cctvDIr[10];
int dx[] = {0, 0,0,-1,1 };
int dy[] = {0, -1,1,0,0 };
int ans = 987654321;
struct Info{
	int x;
	int y;
	int num;
};

vector<Info> cctv;
bool isIn(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
void check(int x, int y, int dir) {
	visit[y][x] = true;
	while (true) {
		if (!isIn(x + dx[dir], y + dy[dir]))
			break;
		if (map[y + dy[dir]][x + dx[dir]] == 6)
			break;
		x += dx[dir];
		y += dy[dir];
		visit[y][x] = true;
	}
}
void search(Info cc,int dir) {
	if (cc.num == 1) {
		if (dir == 1) {
			check(cc.x, cc.y, dir);
		}
		else if (dir == 2) {
			check(cc.x, cc.y, dir);
		}
		else if (dir == 3) {
			check(cc.x, cc.y, dir);
		}
		else {
			check(cc.x, cc.y, dir);
		}
	}
	else if (cc.num == 2) {
		if (dir == 1 || dir == 3) {
			check(cc.x, cc.y, 3);
			check(cc.x, cc.y, 4);
		}
		else {
			check(cc.x, cc.y, 1);
			check(cc.x, cc.y, 2);
		}
	}
	else if (cc.num == 3) {
		if (dir == 1) {
			check(cc.x, cc.y, 1);
			check(cc.x, cc.y, 3);
		}
		else if (dir == 2) {
			check(cc.x, cc.y, 1);
			check(cc.x, cc.y, 4);
		}
		else if (dir == 3) {
			check(cc.x, cc.y, 2);
			check(cc.x, cc.y, 3);
		}
		else {
			check(cc.x, cc.y, 2);
			check(cc.x, cc.y, 4);
		}
	}
	else if (cc.num == 4) {
		if (dir == 1) {
			check(cc.x, cc.y, 2);
			check(cc.x, cc.y, 3);
			check(cc.x, cc.y, 4);
		}
		else if (dir == 2) {
			check(cc.x, cc.y, 1);
			check(cc.x, cc.y, 3);
			check(cc.x, cc.y, 4);
		}
		else if (dir == 3) {
			check(cc.x, cc.y, 1);
			check(cc.x, cc.y, 2);
			check(cc.x, cc.y, 4);
		}
		else {
			check(cc.x, cc.y, 1);
			check(cc.x, cc.y, 2);
			check(cc.x, cc.y, 3);
		}
	}
	else if (cc.num == 5) {
		check(cc.x, cc.y, 1);
		check(cc.x, cc.y, 2);
		check(cc.x, cc.y, 3);
		check(cc.x, cc.y, 4);
	}
}

void solve(int idx) {
	if (idx == cctv.size()) {
		for (int i = 0; i < cctv.size(); i++) {
			search(cctv[i], cctvDIr[i]);
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0 && visit[i][j] == false)
					cnt++;
				visit[i][j] = false;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		cctvDIr[idx] = i;
		solve(idx + 1);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv.push_back({ j, i, map[i][j] });
			}
		}
	}
	solve(0);
	cout << ans << '\n';
	return 0;
}