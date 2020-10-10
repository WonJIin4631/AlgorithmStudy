#include<iostream>
#include<queue>
#include<cstring>
using namespace std;


struct Info {
	int x;
	int y;
};
int N;
int redCan[4][4];
bool greenCan[6][4] = { 0 };
bool blueCan[4][6] = { 0 };
int score = 0;

int greenBlock[6][4] = { 0 };
int blueBlock[4][6] = { 0 };
int greenBlockDist[25] = { 0 };
int blueBlockDist[25] = { 0 };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<Info> q;
void blockMove(int n, int x, int y) {
	//그린
	for (int i = 0; i < 6; i++) {
		if (n == 1) {
			if (greenCan[i][x]) {
				greenCan[i - 1][x] = 1;
				break;
			}
			if (i == 5)
				greenCan[i][x] = 1;
		}
		else if (n == 2) {
			if (greenCan[i][x] || greenCan[i][x + 1]) {
				greenCan[i - 1][x] = 1; greenCan[i - 1][x + 1] = 1;
				break;
			}
			if (i == 5)
				greenCan[i][x] = 1, greenCan[i][x + 1] = 1;
		}
		else {
			if (greenCan[i][x]) {
				greenCan[i - 1][x] = 1; greenCan[i - 2][x] = 1;
				break;
			}
			if (i == 5)
				greenCan[i][x] = 1, greenCan[i - 1][x] = 1;

		}
	}
	//블루
	for (int i = 0; i < 6; i++) {
		if (n == 1) {
			if (blueCan[y][i]) {
				blueCan[y][i - 1] = 1;
				break;
			}
			if (i == 5)
				blueCan[y][i] = 1;
		}
		else if (n == 2) {
			if (blueCan[y][i]) {
				blueCan[y][i - 1] = 1; blueCan[y][i - 2] = 1;
				break;
			}
			if (i == 5)
				blueCan[y][i] = 1, blueCan[y][i - 1] = 1;
		}
		else {
			if (blueCan[y][i] || blueCan[y + 1][i]) {
				blueCan[y][i - 1] = 1; blueCan[y + 1][i - 1] = 1;
				break;
			}
			if (i == 5)
				blueCan[y][i] = 1, blueCan[y - 1][i] = 1;

		}
	}
}

bool checkline() {
	//그린 체크
	bool cc = false;
	for (int i = 5; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (greenCan[i][j])
				cnt++;
		}
		if (cnt == 4) {
			cc = true;
			break;
		}
	}
	//블루 체크

	for (int i = 5; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (blueCan[j][i])
				cnt++;
		}
		if (cnt == 4) {
			cc = true;
			break;
		}
	}

	return cc;
}
void lineClear() {
	//라인 확인 후 제거
	while (true) {
		bool flag = true;
		for (int i = 5; i >= 0; i--) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (greenCan[i][j])
					cnt++;
			}
			if (cnt == 4) {
				flag = false;
				score++;
				for (int j = 0; j < 4; j++) {
					greenCan[i][j] = 0;
				}
			}
		}
		if (flag)
			break;
	}
	while (true) {
		bool flag = true;
		for (int i = 5; i >= 0; i--) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (blueCan[j][i])
					cnt++;
			}
			if (cnt == 4) {
				flag = false;
				score++;
				for (int j = 0; j < 4; j++) {
					blueCan[i][j] = 0;
				}
			}
		}
		if (flag)
			break;
	}
}
bool isIn(int x, int y, char c) {
	if (c == 'B')
		return x >= 0 && x < 6 && y >= 0 && y < 4;
	else
		return x >= 0 && x < 4 && y >= 0 && y < 6;
}
void checkSameBlock(int x, int y, int idx, char c) {
	q.push({ x,y });
	if (c == 'B') {
		blueBlock[y][x] = idx;
		while (!q.empty()) {
			Info cur = q.front();
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny, c)) {
					if (blueCan[ny][nx] && blueBlock[ny][nx] == 0) {
						blueBlock[ny][nx] = idx;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	else {
		greenBlock[y][x] = idx;
		while (!q.empty()) {
			Info cur = q.front();
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny, c)) {
					if (greenCan[ny][nx] && greenBlock[ny][nx] == 0) {
						greenBlock[ny][nx] = idx;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
void blockDown() {
	// 초록 블록 떨어진거 확인
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		int can = 0;
		for (int j = 5; j >= 0; j--) {
			if (greenCan[j][i]) {
				if (greenBlock[j][i] == 0) {

					greenBlockDist[++idx] = can;
					can = 0;
					checkSameBlock(i, j, idx, 'G');
				}
				else {
					int tIdx = greenBlock[i][j];
					if (j == 5)
						greenBlockDist[tIdx] = 0;
					if (can > 0) {
						greenBlockDist[tIdx] = min(greenBlockDist[tIdx], can);
					}
				}
			}
			else {
				can++;
			}
		}
	}
	idx = 0;
	//블루 블록 떨어진거 확인
	for (int i = 0; i < 4; i++) {
		int can = 0;
		for (int j = 5; j >= 0; j--) {
			if (blueCan[i][j]) {
				if (blueBlock[i][j] == 0) {
					blueBlockDist[++idx] = can;
					can = 0;
					checkSameBlock(j, i, idx, 'B');
				}
				else {
					int tIdx = blueBlock[i][j];
					if (j == 5)
						blueBlockDist[tIdx] = 0;
					if (can > 0) {
						blueBlockDist[tIdx] = min(blueBlockDist[tIdx], can);
					}
				}
			}
			else {
				can++;
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (greenBlock[i][j] != 0) {
				int dist = greenBlockDist[greenBlock[i][j]];
				greenCan[i][j] = 0;
				greenCan[i + dist][j] = 1;
			}
			greenBlock[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blueBlock[i][j] != 0) {
				int dist = blueBlockDist[blueBlock[i][j]];
				blueCan[i][j] = 0;
				blueCan[i][j + dist] = 1;
			}
			blueBlock[i][j] = 0;
		}
	}
	memset(greenBlockDist, 0, sizeof(greenBlockDist));
	memset(blueBlockDist, 0, sizeof(blueBlockDist));
}
void clearBlock() {
	int depth = 2;
	for (int i = 0; i < 2; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			if (greenCan[i][j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
		depth--;
	}
	for (int i = 5; i >= 2; i--) {
		for (int j = 0; j < 4; j++) {
			greenCan[i][j] = greenCan[i - depth][j];
		}
	}
	for (int i = 0; i < 4; i++)
		greenCan[0][i] = 0, greenCan[1][i] = 0;

	depth = 2;
	for (int i = 0; i < 2; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			if (blueCan[j][i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
		depth--;
	}
	for (int i = 5; i >= 2; i--) {
		for (int j = 0; j < 4; j++) {
			blueCan[j][i] = blueCan[j][i - depth];
		}
	}
	for (int i = 0; i < 4; i++)
		blueCan[i][0] = 0, blueCan[i][1] = 0;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n, y, x;
		cin >> n >> y >> x;
		blockMove(n, x, y);
		while (checkline()) {
			lineClear();
			blockDown();
		}
		clearBlock();

	}
	int cntBlcok = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (greenCan[i][j])
				cntBlcok++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blueCan[i][j])
				cntBlcok++;
		}
	}
	cout << score << '\n';
	cout << cntBlcok << '\n';
}