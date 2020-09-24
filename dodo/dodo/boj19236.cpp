#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Info{
	int x;
	int y;
	int dir;
};
Info shark;
bool visit[5][5];
bool catchFish[17] = { 0 };
int dx[] = {0, 0,-1,-1,-1,0,1,1,1 };
int dy[] = {0, -1,-1,0,1,1,1,0,-1 };

int ans = 0;

bool isIn(int x, int y) {
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}
int chg_dir(int n) {
	n++;
	if (n == 9)
		n = 1;
	return n;
}
void fishMove(vector<vector<int>>& m,vector<Info>& f) {
	for (int i = 1; i <= 16; i++) {
		if (catchFish[i])
			continue;
		bool flag = false;
		int x = f[i].x;
		int y = f[i].y;
		for (int dd = 0; dd < 9; dd++) {
			int d = f[i].dir;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (!isIn(nx, ny)) {
				f[i].dir = chg_dir(d);
				continue;
			}
			if (nx == shark.x&&ny == shark.y) {
				f[i].dir = chg_dir(d);
				continue;
			}
			flag = true;
			break;
		}
		if (flag) {
			int d = f[i].dir;
			cout <<i<<' '<< d << '\n';
			int nx = x + dx[d];
			int ny = y + dy[d];
			int nIdx = m[ny][nx];
			swap(m[y][x], m[ny][nx]);
			f[nIdx].x = x; f[nIdx].y = y;
			f[i].x = nx; f[i].y = ny;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "--------------------------\n";
	}
}
void solve(Info ss,int sum,vector<Info> f,vector<vector<int>> m) {
	fishMove(m, f);
	cout << sum << '\n';
	int  x = ss.x;
	int y = ss.y;
	int d = ss.dir;
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		x += dx[d];
		y += dy[d];
		if (isIn(x, y)) {
			if (m[y][x] == 0)
				continue;
			catchFish[m[y][x]] = true;
			ss.x = x;
			ss.y = y;
			ss.dir = f[m[y][x]].dir;
			int temp = m[y][x];
			m[y][x] = 0;
			solve(ss, sum + temp, f, m);
			catchFish[m[y][x]] = false;
			m[y][x] = temp;
		}
		else {
			flag = true;
			break;
		}
	}
	if (flag) {
		ans = max(ans, sum);
	}
}
int main() {
	vector<Info> fish;
	fish.resize(17);
	vector<vector<int>> map(4, vector<int>(4, 0));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num,dir;
			cin >> num >> dir;
			fish[num] = { j,i,dir };
			map[i][j] = num;
		}
	}
	shark.x = 0;
	shark.y = 0;
	shark.dir = fish[map[0][0]].dir;
	int stSum = map[0][0];
	catchFish[map[0][0]] = true;
	map[0][0] = 0;
	solve(shark, stSum, fish, map);
	cout << ans << '\n';
	return 0;
}