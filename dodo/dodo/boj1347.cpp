#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
ȫ���̴� �̷ξ� �� ĭ���� ������ �����ִ�.�̷δ� ���簢�� ���, �� ĭ�� �̵��Ҽ� �ְ�, ���� �����Ѵ�.
ȫ���̴� �̷ο� �����ϼ� �ִ� ���ĭ�� �����δ�.
�ڽ��� �������� ���� �ϳ��� �ѹ��� ������ F ������ ��ĭ L,R�� ���� ������ ��ȯ

2���� �迭 ���� ��ó������ �� ���̶�� �ΰ� �̵��Ѱ��� '.'�� �����
2���� �迭�� [102][102] ���ڿ����̰� �ִ� 50�̱⶧��
�־��� ���ǿ� �°� �̵��Ѵ� ó���� ��ġ�� 50,50 �̶�� �ΰ� �̵��ϸ� �迭 ���
���μ��� �ּ� �ִ밪�� ������ �־� �׹��� �� ������ ���
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