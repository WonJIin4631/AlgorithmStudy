#include<iostream>
#include<queue>

using namespace std;

char map[12][6];
int dir[4][2] ={ { -1,0 }, {0, -1}, { 1,0 }, { 0,1 } };
int cnt = 0;
int visit[12 + 1][6 + 1] = { 0, };
bool check = true;
queue<pair<int, int>> q;

bool inPos(int y, int x) {
	if (y < 0 || y >= 12 || x < 0 || x >= 6)
		return false;
	else
		return true;
}
void rePaint() {
	for (int i = 0; i < 6; i++) {
		for (int j = 10; j >= 0; j--) {
			for (int k = 11; k > j; k--) {
				if (map[j][i] != '.'&&map[k][i] == '.') {
					map[k][i] = map[j][i];
					map[j][i] = '.';
					break;
				}
			}
		}
	}
}


void change() {
	while (!q.empty()) {
		map[q.front().first][q.front().second] = '.';
		visit[q.front().first][q.front().second] = 0;
		q.pop();
	}
}

void DFS(char s, int a, int b) {
	if (inPos(a, b) && visit[a][b] == 0) {
		visit[a][b] = 1;
		q.push(make_pair(a, b));
		if (map[a + dir[0][0]][b + dir[0][1]] == s) {
			DFS(s, a + dir[0][0], b + dir[0][1]);
		}
		if (map[a + dir[1][0]][b + dir[1][1]] == s) {
			DFS(s, a + dir[1][0], b + dir[1][1]);
		}
		if (map[a + dir[2][0]][b + dir[2][1]] == s) {
			DFS(s, a + dir[2][0], b + dir[2][1]);
		}
		if (map[a + dir[3][0]][b + dir[3][1]] == s) {
			DFS(s, a + dir[3][0], b + dir[3][1]);
		}
	}
}


void Puyo() {
		check = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					DFS(map[i][j], i, j);
					if (q.size() >= 4) {
						change();
						check = true;
					}
					else {
						while (!q.empty()) {
							visit[q.front().first][q.front().second] = 0;
							q.pop();
						}
					}
				}
			}
		}
		rePaint();
		if (check) {
			cnt++;
			Puyo();
		}
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin>>map[i][j];
		}
	}
	Puyo();
	cout << cnt <<endl;
}