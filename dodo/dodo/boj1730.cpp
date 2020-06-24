#include<iostream>
#include<string>
using namespace std;

struct Info{
	int x;
	int y;
};
bool map[2][101][101] = { 0 };
int N;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
Info robot;
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
int get_dir(char c) {
	if (c == 'D')
		return 1;
	else if (c == 'U')
		return 0;
	else if (c == 'R')
		return 3;
	else if (c == 'L')
		return 2;
}
void draw_map(int x, int y, int d) {
	if (d == 0||d==1) {
		map[0][y][x] = true;
	}
	else if (d == 2 || d == 3) {
		map[1][y][x] = true;
	}
}
int main() {
	cin >> N;
	robot = { 0,0 };
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		int d = get_dir(input[i]);
		int nx = robot.x + dx[d];
		int ny = robot.y + dy[d];
		if (isIn(nx, ny)) {
			draw_map(robot.x, robot.y, d);
			draw_map(nx, ny, d);
			robot.x = nx;
			robot.y = ny;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!(map[0][i][j] || map[1][i][j])) {
				cout << '.';
			}
			else if (map[0][i][j] && map[1][i][j]) {
				cout << '+';
			}
			else if (map[0][i][j]) {
				cout << '|';
			}
			else if (map[1][i][j]) {
				cout << '-';
			}
		}
		cout << '\n';
	}
	return 0;
}