#include<iostream>
using namespace std;

int N;
int map[501][501];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int sandx[] = { 0,-1,0,1,-2,-1,0,1,0 };
int sandy[] = { -2,-1,-1,-1,0,1,1,1,2 };
int sandPercent[] = { 2,10,7,1,5,10,7,1,2 };
bool Isin(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
}
int sandMove(int x, int y, int dir) {
	int totalSand = map[y][x];
	int outSand = 0;
	int changeDir = 1;
	if (dir == 1 || dir == 2)
		changeDir = -1;
	for (int i = 0; i < 9; i++) {
		if (dir == 0 || dir == 2) {
			int nx = x + (sandx[i] * changeDir);
			int ny = y + (sandy[i] * changeDir);
			int tempSand = (map[y][x] * sandPercent[i]) / 100;
			totalSand -= tempSand;
			if (Isin(nx, ny)) {
				map[ny][nx] += tempSand;
			}
			else {
				outSand += tempSand;
			}
		}
		else {
			int nx = x + (sandy[i] * changeDir);
			int ny = y + (sandx[i] * changeDir);
			int tempSand = (map[y][x] * sandPercent[i]) / 100;
			totalSand -= tempSand;
			if (Isin(nx, ny)) {
				map[ny][nx] += tempSand;
			}
			else {
				outSand += tempSand;
			}
		}
	}
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (Isin(nx, ny)) {
		map[ny][nx] += totalSand;
	}
	else {
		outSand += totalSand;
	}
	map[y][x] = 0;
	return outSand;
}
int tornadoMove() {
	int leftPos, rightPos, downPos, upPos;
	leftPos = N / 2 - 1, rightPos = N / 2 + 1, downPos = N / 2 + 1, upPos = N / 2 - 1;
	int curx = N / 2;
	int cury = N / 2;
	int curDir = 0;
	int totalOutSand = 0;
	while (true) {
		if (curx < 0 ) {
			break;
		}
		curx += dx[curDir];
		cury += dy[curDir];
		totalOutSand+=sandMove(curx, cury,curDir);
		if (curDir == 0 && leftPos == curx)
			leftPos--, curDir = 1;
		else if (curDir == 1 && downPos == cury)
			downPos++, curDir = 2;
		else if (curDir == 2 && rightPos == curx)
			rightPos++, curDir = 3;
		else if (curDir == 3 && upPos == cury)
			upPos--, curDir = 0;
	}
	return totalOutSand;
}
void solve() {
	init();
	cout<<tornadoMove()<<'\n';
}
int main() {
	solve();

	return 0;
}