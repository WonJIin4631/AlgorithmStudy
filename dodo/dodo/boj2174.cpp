#include<iostream>
using namespace std;

struct info
{
	int x;
	int y;
	char dir;
};
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int map[102][102] = { 0 };
int W, H, N, M;
info robot[101];
int get_dir(char c) {
	if (c == 'N')
		return 0;
	if (c == 'S')
		return 2;
	if (c == 'W')
		return 1;
	if (c == 'E')
		return 3;
}
char cng_dir(int n) {
	if (n == 0)
		return 'N';
	if (n == 2)
		return 'S';
	if (n == 1)
		return 'W';
	if (n == 3)
		return 'E';
}
int main() {
	cin >> W >> H;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> robot[i].x >> robot[i].y >> robot[i].dir;
		map[robot[i].y][robot[i].x] = i;
	}
	bool flag = false;
	for (int i = 0; i < M; i++) {
		int idx, cnt;
		char c;
		cin >> idx >> c >> cnt;
		int x = robot[idx].x;
		int y = robot[idx].y;
		int d = get_dir(robot[idx].dir);
		int nx = x;
		int ny = y;
		int nd = d;
		if (c != 'F')
			cnt %= 4;
		for (int j = 1; j <= cnt; j++) {
			if (c == 'F') {
				nx += dx[nd];
				ny += dy[nd];
				if (nx < 1 || nx > W || ny < 1 || ny > H) {
					cout << "Robot " << idx << " crashes into the wall\n";
					flag = true;
					break;
				}
				else if (map[ny][nx] != 0) {
					cout << "Robot " << idx << " crashes into robot " << map[ny][nx] << '\n';
					flag = true;
					break;
				}
			}
			else if (c == 'L') {
				if (nd == 3)
					nd = 0;
				else
					nd++;
			}
			else {
				if (nd == 0)
					nd = 3;
				else
					nd--;
			}
		}
		if (flag)
			break;
		map[y][x] = 0;
		map[ny][nx] = idx;
		robot[idx].x = nx;
		robot[idx].y = ny;
		robot[idx].dir = cng_dir(nd);

	}
	if (!flag)
		cout << "OK" << '\n';

	return 0;
}
