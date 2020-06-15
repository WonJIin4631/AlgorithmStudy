#include<iostream>
#include<vector>
using namespace std;

struct Info{
	int x;
	int y;
};

vector<Info> v;
bool ans = false;
int map[10][10];
bool garo[9][10] = {0};
bool sero[9][10] = { 0 };
bool block[9][10] = { 0 };

void solve(int idx, int cnt) {
	if (cnt == v.size()) {
		if (ans)
			return;
		ans = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	int x = v[idx].x;
	int y = v[idx].y;
	for (int i = 1; i <= 9; i++) {
		if (garo[y][i] == false) {
			if (sero[x][i] == false) {
				int bb = (y / 3) * 3 + (x / 3);
				if (block[bb][i] == false) {
					garo[y][i] = true;
					sero[x][i] = true;
					block[bb][i] = true;
					map[y][x] = i;
					solve(idx + 1, cnt + 1);
					garo[y][i] = false;
					sero[x][i] = false;
					block[bb][i] = false;
				}
			}
		}
	}
}
void checkNum() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] != 0)
				garo[i][map[i][j]] = true;
			if (map[j][i] != 0)
				sero[i][map[j][i]] = true;	
		}
	}
	int x = 0;
	int y = 0;
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int ii = y; ii < y+3; ii++) {
				for (int jj = x; jj < x+3; jj++) {
					if (map[ii][jj] == 0)
						continue;
					block[idx][map[ii][jj]] = true;
				}
			}
			idx++;
			x += 3;
		}
		x = 0;
		y += 3;
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back({ j,i });
		}
	}
	checkNum();
	solve(0,0);
	return 0;
}