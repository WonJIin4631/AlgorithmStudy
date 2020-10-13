#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Info {
	int x;
	int y;
	int d;
};
Info shark;
bool catchedFish[17] = { 0 };
vector<Info> fish(17, { 0,0,0 });
int dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };

int ans = 0;
bool isIn(int x, int y) {
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}
void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n, d;
			cin >> n >> d;
			if (i == 0 && j == 0) {
				ans += n;
				catchedFish[n] = true;
				shark.x = j;
				shark.y = i;
				shark.d = d;
				continue;
			}
			fish[n] = { j,i,d };
		}
	}
}

vector<Info> fishMove(vector<Info> f, bool c[], Info s) {
	int map[5][5] = { 0 };
	for (int i = 1; i <= 16; i++) {
		if (c[i] == true)
			continue;
		map[f[i].y][f[i].x] = i;
	}
	for (int i = 1; i <= 16; i++) {
		if (c[i] == false) {
			int curDir = f[i].d;
			bool flag = false;
			for (int d = 0; d < 8; d++) {
				int nx = f[i].x + dx[curDir];
				int ny = f[i].y + dy[curDir];
				if (isIn(nx, ny)) {
					if (nx != s.x || ny != s.y) {
						int nfish = map[ny][nx];
						if (nfish == 0) {
							map[f[i].y][f[i].x] = 0;
							f[i].x = nx;
							f[i].y = ny;
							map[f[i].y][f[i].x] = i;
						}
						else {
							map[f[i].y][f[i].x] = nfish;
							map[ny][nx] = i;
							int tx = f[i].x;
							int ty = f[i].y;
							f[i].x = nx; f[i].y = ny;
							f[nfish].x = tx; f[nfish].y = ty;	
						}
						flag = true;
					}
				}
				f[i].d = curDir;
				if (flag)
					break;
				curDir++;
				if (curDir > 8)
					curDir = 1;
			}
		}
	}
	return f;
}


void solve(vector<Info> f, bool c[], Info s) {
	int map[5][5] = { 0 };
	int val = 0;
	f = fishMove(f, c, s);
	for (int i = 1; i <= 16; i++) {
		if (c[i] == true) {
			val += i;
			continue;
		}
		map[f[i].y][f[i].x] = i;
	}
	ans = max(ans, val);
	
	for (int i = 1; i <= 4; i++) {
		int nx = s.x + dx[s.d] * i;
		int ny = s.y + dy[s.d] * i;
		if (isIn(nx, ny)) {
			if (map[ny][nx] == 0)
				continue;
			int fn = map[ny][nx];
			c[fn] = true;
			map[ny][nx] = 0;
			solve(f, c, f[fn]);
			map[ny][nx] = fn;
			c[fn] = false;
		}
	}
}
int main() {
	init();
	solve(fish, catchedFish, shark);
	cout << ans << '\n';

	return 0;
}