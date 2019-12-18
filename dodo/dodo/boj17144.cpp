#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int map[51][51];
struct pos {
	int y;
	int x;
};
pos aircon[2];
int R, C, T;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> v;
int ans = 0;
void cal() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	cout << ans << '\n';
}
void air_move() {
	deque<int> dq;

	for (int i = 1; i < C; i++) {
		dq.push_back(map[aircon[0].y][i]);
	}
	for (int i = aircon[0].y - 1; i > 0; i--) {
		dq.push_back(map[i][C - 1]);
	}
	for (int i = C - 1; i >= 0; i--) {
		dq.push_back(map[0][i]);
	}
	for (int i = 1; i < aircon[0].y; i++) {
		dq.push_back(map[i][0]);
	}
	dq.push_front(0);
	dq.pop_back();
	for (int i = 1; i < C; i++) {
		map[aircon[0].y][i] = dq.front();
		dq.pop_front();
	}
	for (int i = aircon[0].y - 1; i > 0; i--) {
		map[i][C - 1] = dq.front();
		dq.pop_front();
	}
	for (int i = C - 1; i >= 0; i--) {
		map[0][i] = dq.front();
		dq.pop_front();
	}
	for (int i = 1; i < aircon[0].y; i++) {
		map[i][0] = dq.front();
		dq.pop_front();
	}
	for (int i = 1; i < C; i++) {
		dq.push_back(map[aircon[1].y][i]);
	}
	for (int i = aircon[1].y + 1; i <R - 1; i++) {
		dq.push_back(map[i][C - 1]);
	}
	for (int i = C - 1; i >= 0; i--) {
		dq.push_back(map[R - 1][i]);
	}
	for (int i = R - 2; i > aircon[1].y; i--) {
		dq.push_back(map[i][0]);
	}
	dq.push_front(0);
	dq.pop_back();
	for (int i = 1; i < C; i++) {
		map[aircon[1].y][i] = dq.front();
		dq.pop_front();
	}
	for (int i = aircon[1].y + 1; i <R - 1; i++) {
		map[i][C - 1] = dq.front();
		dq.pop_front();
	}
	for (int i = C - 1; i >= 0; i--) {
		map[R - 1][i] = dq.front();
		dq.pop_front();
	}
	for (int i = R - 2; i > aircon[1].y; i--) {
		map[i][0] = dq.front();
		dq.pop_front();
	}

}

void mise() {
	int tmp_map[51][51] = { 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				int mise_size = map[i][j];
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (ny >= 0 && ny < R&&nx >= 0 && nx < C) {
						if (map[ny][nx] != -1) {
							tmp_map[ny][nx] += mise_size / 5;
							cnt++;
						}
					}
				}
				tmp_map[i][j] += map[i][j] - (mise_size / 5)*cnt;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp_map[i][j];
		}
	}
	map[aircon[0].y][aircon[0].x] = -1;
	map[aircon[1].y][aircon[1].x] = -1;
}
int main() {
	cin >> R >> C >> T;
	int air_cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				aircon[air_cnt].y = i;
				aircon[air_cnt++].x = j;
			}
		}
	}
	for (int i = 0; i < T; i++) {
		mise();
		air_move();
	}
	cal();
}