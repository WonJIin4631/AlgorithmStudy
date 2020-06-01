#include<iostream>

#include<algorithm>
using namespace std;

int N, L;
int map[101][101] = { 0 };
int ans = 0;
bool check(int x,int y,char dir) {
	int cnt = 0;
	bool check[101] = { 0 };
	if (dir == 'R') {
		for (int i = 0; i < N-1; i++) {
			if (map[y][i] == map[y][i + 1]) {
				cnt++;
			}
			//³ôÀ½
			else if (map[y][i] + 1 == map[y][i + 1]) {
				if (cnt + 1 < L)
					return false;
				int tx = i;
				for (int j = 0; j < L; j++) {
					if (check[tx])
						return false;
					if (tx < 0)
						return false;
					if (map[y][tx] != map[y][i])
						return false;
					check[tx] = true;
					tx--;
				}
				cnt = 0;
			}
			//³·À½
			else if (map[y][i] - 1 == map[y][i + 1]) {
				int tx = i + 1;
				for (int j = 0; j < L; j++) {
					if (check[tx])
						return false;
					if (tx >= N)
						return false;
					if (map[y][tx] != map[y][i+1])
						return false;
					check[tx] = true;
					tx++;
				}
				i = tx-2;
				cnt = 0;
			}
			else
				return false;
		}
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			if (map[i][x] == map[i+1][x]) {
				cnt++;
			}
			//³ôÀ½
			else if (map[i][x]+1 == map[i+1][x]) {
				if (cnt + 1 < L)
					return false;
				int ty = i;
				for (int j = 0; j < L; j++) {
					if (check[ty])
						return false;
					if (ty < 0)
						return false;
					if (map[ty][x] != map[i][x])
						return false;
					check[ty] = true;
					ty--;
				}
				cnt = 0;
			}
			//³·À½
			else if (map[i][x]-1 == map[i+1][x]) {
				int ty = i + 1;
				for (int j = 0; j < L; j++) {
					if (check[ty])
						return false;
					if (ty >= N)
						return false;
					if (map[ty][x] != map[i+1][x])
						return false;
					check[ty] = true;
					ty++;
				}
				i = ty-2;
				cnt = 0;
			}
			else
				return false;
		}
	}
	return true;
}
void solve() {
	for (int i = 0; i < N; i++) {
		if (check(0, i, 'R')) {
			ans++;
		}
		if (check(i, 0, 'D')) {
			ans++;
		}
	}
	cout << ans << '\n';
}
void init() {
	cin >> N>>L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	init();
	solve();
	return 0;
}