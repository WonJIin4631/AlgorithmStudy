#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
홍준이는 미로안 한 칸에서 남쪽을 보고있다.미로는 직사각형 모양, 각 칸을 이동할수 있고, 벽을 포함한다.
홍준이는 미로에 움직일수 있는 모든칸을 움직인다.
자신의 움직임을 문자 하나는 한번의 움직임 F 앞으로 한칸 L,R은 왼쪽 오른쪽 전환

2차원 배열 선언 맨처음에는 다 벽이라고 두고 이동한곳을 '.'로 만들기
2차원 배열은 [102][102] 문자열길이가 최대 50이기때문
주어진 조건에 맞게 이동한다 처음의 위치는 50,50 이라고 두고 이동하며 배열 기록
가로세로 최소 최대값을 가지고 있어 그범위 내 모든곳을 출력
*/

char map[102][102];
int curX, curY, curDir;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int N;
char miro[52];
int changeDir(int d, char c) {
	if (c == 'R') {
		d--;
		if (d < 0)
			d = 3;
	}
	else {
		d++;
		if (d > 3)
			d = 0;
	}
	return d;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> miro[i];
	}
	for (int i = 0; i <= N * 2 + 1; i++) {
		for (int j = 0; j <= N * 2 + 1; j++) {
			map[i][j] = '#';
		}
	}
	curX = curY = N;
	curDir = 2;
	map[curY][curX] = '.';
	int minX, maxX, minY, maxY;
	minX = minY = maxX = maxY = N;
	for (int i = 0; i < N; i++) {
		if (miro[i] == 'F') {
			curX += dx[curDir];
			curY += dy[curDir];
			map[curY][curX] = '.';
		}
		else {
			curDir = changeDir(curDir, miro[i]);
		}
		minX = min(minX, curX);
		maxX = max(maxX, curX);
		minY = min(minY, curY);
		maxY = max(maxY, curY);
	}
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}