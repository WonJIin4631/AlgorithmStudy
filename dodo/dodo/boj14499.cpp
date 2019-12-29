#include <iostream>
using namespace std;

int m, n;
int diex, diey;
int K;
int map[22][22];
int cmd[1001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int die[6] = { 0, };

void dice_move(int d) {
	switch (d) {
	case 0:
		swap(die[2], die[0]);
		swap(die[0], die[3]);
		swap(die[3], die[5]);
		break;
	case 1:
		swap(die[3], die[0]);
		swap(die[0], die[2]);
		swap(die[2], die[5]);
		break;
	case 2:
		swap(die[4], die[5]);
		swap(die[0], die[4]);
		swap(die[1], die[0]);
		break;
	case 3:
		swap(die[1], die[0]);
		swap(die[0], die[4]);
		swap(die[4], die[5]);
		break;
	}

}


void solve() {
	int x = diex;
	int y = diey;
	for (int i = 0; i < K; i++) {
		int nx = x + dx[cmd[i]-1];
		int ny = y + dy[cmd[i]-1];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) 
			continue;

		dice_move(cmd[i]-1);

		if (map[nx][ny] == 0) {
			map[nx][ny] = die[5];
		}
		else {
			die[5] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << die[0] << endl;
		x = nx;
		y = ny;
	}
}

int main() {
	cin >> m >> n >> diex >> diey >> K;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin>>cmd[i];
	}
	solve();
	return 0;
}
