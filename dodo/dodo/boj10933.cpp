#include<iostream>
#include<cmath>
using namespace std;
/*
꼭지점 위치 상(홀수),하(짝수)
높이 2^N-1
넓이 2^(N+1)-3
*/

char map[1024][2048];
int N;
void func(int y, int x, int h) {
	if (h == 1) {
		map[y][x] = '*';
		return;
	}
	int W = pow(2, h + 1) - 3;
	int H = pow(2, h) - 1;
	if (h % 2) {
		for (int i = 0; i < H - 1; i++) {
			map[y + i][x + W / 2 - i] = '*';
			map[y + i][x + W / 2 + i] = '*';
		}
		for (int i = 0; i < W; i++) {
			map[y + H - 1][x + i] = '*';
		}
		func(y + H / 2, x + pow(2, h - 1), h - 1);
		return;
	}
	for (int i = 1; i < H; i++) {
		map[y + i][x + i] = '*';
		map[y + i][x + W - (i + 1)] = '*';
	}
	for (int i = 0; i < W; i++) {
		map[y][x + i] = '*';
	}
	func(y + 1, x + pow(2, h - 1), h - 1);
	return;
}
int main() {
	cin >> N;
	func(0, 0, N);
	int W = pow(2, N + 1) - 3;
	int H = pow(2, N) - 1;
	for (int i = 0; i < H; i++) {
		if (N % 2) {
			for (int j = 0; j < W - H + (i + 1); j++) {
				char c = map[i][j] == '*' ? '*' : ' ';
				cout << c;
			}
			cout << '\n';
			continue;
		}
		for (int j = 0; j < W - i; j++) {
			char c = map[i][j] == '*' ? '*' : ' ';
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}