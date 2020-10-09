#include <iostream>
#include <algorithm>
using namespace std;


int map[1002][1002];
int primap[1002][1002];
int main() {
	int N, M;
	int line[2][1000];

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	primap[0][0] = map[0][0];
	for (int i = 1; i < M; i++) {
		primap[0][i] = primap[0][i - 1] + map[0][i];
	}
	for (int h = 1; h < N; h++) {
		for (int r = 0; r < M; r++) {
			line[0][r] = line[1][r] = primap[h - 1][r] + map[h][r];
		}
		//¿À¸¥ÂÊ
		for (int r = 1; r < M; r++) {
			line[0][r] = max(line[0][r], line[0][r - 1] + map[h][r]);
		}
		//¿ÞÂÊ
		for (int r = M - 2; r >= 0; r--) {
			line[1][r] = max(line[1][r], line[1][r + 1] + map[h][r]);
		}
		for (int r = 0; r < M; r++) {
			primap[h][r] = max(line[0][r], line[1][r]);
		}
	}
	cout << primap[N - 1][M - 1] << '\n';
	return 0;
}
