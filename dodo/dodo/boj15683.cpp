#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct Info{
	int x;
	int y;
	int n;
};
int N, M;
int map[9][9];
bool visit[9][9];
int cam[9][4] = { 0 };
int camDir[9] = { 0 };
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
vector<Info> v;
int ans = 987654321;
bool isin(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}

void pasteCan(int x, int y, int dir) {
	visit[y][x] = true;
	while (true) {
		x += dx[dir];
		y += dy[dir];
		if (!isin(x, y))
			break;
		if (map[y][x] == 6)
			break;
		if (visit[y][x])
			continue;
		visit[y][x] = true;
	}
}

void chooseCan(int idx) {
	if (v[idx].n == 1) {
		pasteCan(v[idx].x, v[idx].y, camDir[idx]);
	}
	else if (v[idx].n == 2) {
		if (camDir[idx] == 0 || camDir[idx] == 2) {
			pasteCan(v[idx].x, v[idx].y,0);
			pasteCan(v[idx].x, v[idx].y, 2);
		}
		else if(camDir[idx] == 1 || camDir[idx] == 3) {
			pasteCan(v[idx].x, v[idx].y, 1);
			pasteCan(v[idx].x, v[idx].y, 3);
		}
	}
	else if (v[idx].n == 3) {
		int nd = camDir[idx] + 1;
		if (nd == 4)
			nd = 0;
		pasteCan(v[idx].x, v[idx].y, camDir[idx]);
		pasteCan(v[idx].x, v[idx].y, nd);
	}
	else if (v[idx].n == 4) {
		for (int i = 0; i < 4; i++) {
			if (i == camDir[idx])
				continue;
			pasteCan(v[idx].x, v[idx].y, i);
		}
	}
	else if (v[idx].n == 5) {
		for (int i = 0; i < 4; i++) {
			pasteCan(v[idx].x, v[idx].y, i);
		}
	}
}
void solve(int idx) {
	if (idx == v.size()) {
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < idx; i++) {
			chooseCan(i);
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 6)
					continue;
				if (visit[i][j] == false) {
					cnt++;
				}
			}
		}
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		camDir[idx] = i;
		solve(idx + 1);
	}
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				v.push_back({ j,i,map[i][j] });
			}
		}
	}
}
int main() {
	init();
	solve(0);
	cout << ans << '\n';
	return 0;
}