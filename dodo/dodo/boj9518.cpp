#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int R, S;
int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
char map[51][51];
bool check[2501][8] = { 0 };
int ans = 0;
int maxCnt = 0;
int getDir(int d) {
	int n = abs(d - 7);
	return n;
}
bool isIn(int x, int y) {
	return x >= 0 && x < S&&y >= 0 && y < R;
}
void solve() {
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (map[i][j] == 'o') {
				//8가지 방향 확인
				for (int d = 0; d < 8; d++) {
					int nx = j + dx[d];
					int ny = i + dy[d];
					if (isIn(nx, ny)) {
						int curIdx = (i*S) + j;
						if (map[ny][nx] == 'o') {
							//이전에 악수를 했는지 확인
							if (!check[curIdx][d]) {
								int nIdx = (ny*S) + nx;
								int tDir = getDir(d);
								check[nIdx][tDir] = true;
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	ans = max(ans, cnt);

}
void DFS(int x, int y, bool gg) {
	if (gg) {
		int tt = 0;
		//상근이 주변사람과 악수하는 횟수 확인
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isIn(nx, ny)) {
				if (map[ny][nx] == 'o')
					tt++;
			}
		}
		if (maxCnt <= tt) {
			maxCnt = tt;
			solve();
			memset(check, 0, sizeof(check));
		}
		return;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (map[i][j] == '.') {
				map[i][j] = 'o';
				DFS(j, i, true);
				map[i][j] = '.';
			}
		}
	}
}
int main() {
	cin >> R >> S;
	int tt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o')
				tt++;
		}
	}
	if (tt == R*S) {
		solve();
	}
	else {
		DFS(0, 0, false);
	}
	cout << ans << '\n';
	return 0;
}