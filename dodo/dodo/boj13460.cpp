#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char map[11][11];
bool visit[11][11][11][11] = { 0 };
struct info {
	int x;
	int y;
};
int N, M;
info bb;
info rb;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
info move_b(info b, int d) {
	int x = b.x;
	int y = b.y;
	while (true) {
		if (map[y + dy[d]][x + dx[d]] == '#')
			break;
		x += dx[d];
		y += dy[d];
		if (map[y][x] == 'O')
			break;
	}
	b.x = x; b.y = y;
	return b;
}
void solve() {
	queue<pair<info, info>> q;
	q.push(make_pair(rb, bb));
	int time = 0;
	visit[rb.y][rb.x][bb.y][bb.x] = true;
	while (!q.empty()) {
		if (time >= 10)
			break;
		int sz = q.size();
		for (int t = 0; t < sz; t++) {
			info r = q.front().first;
			info b = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				info nr = move_b(r, i);
				info nb = move_b(b, i);

				if (map[nr.y][nr.x] == 'O') {
					if (map[nb.y][nb.x] != 'O') {
						ans = time+1;
						return;
					}
					else
						continue;
				}
				if (map[nb.y][nb.x] == 'O')
					continue;
				if ((nr.x == nb.x) && (nr.y == nb.y)) {
					int distr = abs(r.x - nr.x) + abs(r.y - nr.y);
					int distb = abs(b.x - nb.x) + abs(b.y - nb.y);
					if (distr < distb) {
						nb.x -= dx[i];
						nb.y -= dy[i];
					}
					else {
						nr.x -= dx[i];
						nr.y -= dy[i];
					}
				}
				if (!visit[nr.y][nr.x][nb.y][nb.x]) {
					visit[nr.y][nr.x][nb.y][nb.x] = true;
					q.push(make_pair(nr, nb));
				}
			}
		}
		time++;
	}
	ans = -1;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				map[i][j] = '.';
				bb.x = j, bb.y = i;
			}
			else if (map[i][j] == 'R') {
				map[i][j] = '.';
				rb.x = j, rb.y = i;
			}
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}