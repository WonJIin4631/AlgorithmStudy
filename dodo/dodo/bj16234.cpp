#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

#define MAX_SIZE 50

int N, L, R;
int country[MAX_SIZE][MAX_SIZE];
int isVisited[MAX_SIZE][MAX_SIZE] = { 0, };
bool ischecked;
int dirX[4] = { -1,1,0,0 };//왼쪽 오른쪽 위 아래
int dirY[4] = { 0,0,-1,1 };
int sum, cnt = 0;
queue<pair<int, int>> q;


bool posIn(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	else
		return false;
}

void DFS(int x, int y) {
	q.push(make_pair(x, y));
	isVisited[x][y] = 1;
	sum += country[x][y];
	if (posIn(x - 1, y)) {
		if (!isVisited[x - 1][y] && abs(country[x][y] - country[x - 1][y]) >= L && abs(country[x][y] - country[x - 1][y]) <= R) {
			DFS(x - 1, y);
			ischecked = true;
		}
	}
	if (posIn(x + 1, y)) {
		if (!isVisited[x + 1][y] && abs(country[x][y] - country[x + 1][y]) >= L && abs(country[x][y] - country[x + 1][y]) <= R) {
			DFS(x + 1, y);
			ischecked = true;
		}
	}
	if (posIn(x, y - 1))
		if (!isVisited[x][y - 1] && abs(country[x][y] - country[x][y - 1]) >= L && abs(country[x][y] - country[x][y - 1]) <= R) {
			DFS(x, y - 1);
			ischecked = true;
		}
	if (posIn(x, y + 1)) {
		if (!isVisited[x][y + 1] && abs(country[x][y] - country[x][y + 1]) >= L && abs(country[x][y] - country[x][y + 1]) <= R) {
			DFS(x, y + 1);
			ischecked = true;
		}
	}
}

int main() {
	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}
	ischecked = true;
	while (ischecked) {
		ischecked = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisited[i][j]) {
					sum = 0;
					DFS(i, j);
					int size = q.size();
					while (!q.empty()) {
						country[q.front().first][q.front().second] = sum / size;
						q.pop();
					}
				}
			}
		}

		if (ischecked)
		{
			cnt++;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					isVisited[i][j] = 0;
				}
			}
		}
	}
	cout << cnt << endl;
}