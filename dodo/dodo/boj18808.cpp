#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
/*
스티커를 회전시키지 않고 노트북에 붙인다.
노트북에 붙일 스티커는 노트북을 벗어나거나 스티커가 겹쳐지면 안된다.
붙일 위치는 가장위 가장 왼쪽에 붙인다.

만약 붙이지 못한다면 시계 방향으로 90도 회전한다.
0,90,180,270 회전해도 붙이지 못하면 버린다.



*/
int N, M, K;
int map[42][42] = { 0 };
int sticker[11][11] = { 0 };
void attach(int i, int j, int r, int c) {
	for (int x = i; x < i + r; x++) {
		for (int y = j; y < j + c; y++) {
			if (map[x][y] == 0)
				map[x][y] = sticker[x - i][y - j];
		}
	}
}
void rotate(int r, int c) {
	int temp[10][10];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = sticker[i][j];
		}
	}
	
	memset(sticker, 0, sizeof(sticker));
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			sticker[i][j] = temp[r - 1 - j][i];
		}
	}
}
bool attempt(int r, int c, int cnt) {
	if (cnt == 4)
		return false;
	bool possible = false;
	if (N >= r && M >= c) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				possible = true;
				if (i + r <= N&&j + c <= M) {
					for (int x = 0; x < r; x++) {
						for (int y = 0; y < c; y++) {
							if (sticker[x][y] == 1 && map[i + x][j + y] == 1) {
								possible = false;
								break;
							}
						}
						if (!possible)
							break;
					}
				}
				else {
					possible = false;
				}
				if (possible) {
					attach(i, j, r, c);
					return true;
				}
			}
		}
	}
	if (!possible) {
		rotate(r, c);
		if (attempt(c, r, cnt + 1))
			return true;
		else
			return false;
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> sticker[j][k];
			}
		}
		attempt(n, m, 0);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j])
				ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}