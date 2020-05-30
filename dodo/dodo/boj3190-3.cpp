#include<iostream>
#include<deque>
using namespace std;

int K;
int N;
int L;
bool map[101][101];
bool visit[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
typedef pair<int, int> pii;
deque<pii> ss;
int chg_dir(int d, char c) {
	if (c == 'L') {
		if (d == 0)
			return 3;
		else
			return d - 1;
	}
	else {
		if (d == 3)
			return 0;
		else
			return d + 1;
	}
}
struct info {
	int x;
	int y;
	int dir;
};
int main() {
	cin >> N;
	cin >> K;
	info snake;
	snake = { 0,0,1 };
	ss.push_back(pii(0, 0));
	visit[0][0] = true;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		map[y - 1][x - 1] = true;
	}
	cin >> L;
	bool flag = false;
	int time = 0;
	for (int i = 0; i < L; i++) {
		int t; char dd;
		cin >> t >> dd;
		if (flag)
			continue;
		int x = snake.x;
		int y = snake.y;
		int d = snake.dir;
		while (time < t) {
			time++;
			x += dx[d];
			y += dy[d];
			bool c_apple = false;
			if (x < 0 || x >= N || y < 0 || y >= N) {
				flag = true;
				break;
			}
			if (visit[y][x] == true) {
				flag = true;
				break;
			}
			if (map[y][x] == true) {
				c_apple = true;
				map[y][x] = false;
			}
			ss.push_front(pii(y, x));
			visit[y][x] = true;
			if (!c_apple) {
				int tx = ss.back().second;
				int ty = ss.back().first;
				visit[ty][tx] = false;
				ss.pop_back();

			}
		}
		if (flag)
			continue;

		snake.x = x;
		snake.y = y;
		snake.dir = chg_dir(d, dd);
	}
	if (!flag) {
		int x = snake.x;
		int y = snake.y;
		int d = snake.dir;
		while (true) {
			time++;
			x += dx[d];
			y += dy[d];
			bool c_apple = false;
			if (x < 0 || x >= N || y < 0 || y >= N) {
				break;
			}
			if (visit[y][x] == true) {
				break;
			}
			if (map[y][x] == true) {
				c_apple = true;
				map[y][x] = false;
			}
			ss.push_front(pii(y, x));
			visit[y][x] = true;
			if (!c_apple) {
				int tx = ss.back().second;
				int ty = ss.back().first;
				visit[ty][tx] = false;
				ss.pop_back();
			}
		}
	}
	cout << time  << '\n';
	return 0;
}