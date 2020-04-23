#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

typedef pair<int, pair<int, int>> p;

char map[105][105];
int dist[3][105][105];
int person[3][2];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
int T, W, H;
priority_queue<p, vector<p>, greater<p> > pq;
void BFS() {
	for (int i = 0; i <= H + 1; i++) {
		for (int j = 0; j <= W + 1; j++) {
			dist[0][i][j] = dist[1][i][j] = dist[2][i][j] = 987654321;
			if (i == 0 || i == H + 1 || j == 0 || j == W + 1)
				map[i][j] = '.';
		}
	}
	for (int i = 0; i < 3; i++) {
		dist[i][person[i][0]][person[i][1]] = 0;
		pq.push(make_pair(0, make_pair(person[i][0], person[i][1])));
		while (!pq.empty()) {
			int x = pq.top().second.second;
			int y = pq.top().second.first;
			int cnt = pq.top().first;
			pq.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx <= W + 1 && ny >= 0 && ny <= H + 1) {
					if (map[ny][nx] != '*') {
						if (map[ny][nx] == '#'&&dist[i][ny][nx] > cnt + 1) {
							dist[i][ny][nx] = cnt + 1;
							pq.push(make_pair(cnt + 1, make_pair(ny, nx)));
						}
						else if (map[ny][nx] == '.'&&dist[i][ny][nx] > cnt) {
							dist[i][ny][nx] = cnt;
							pq.push(make_pair(cnt, make_pair(ny, nx)));
						}
					}
				}
			}
		}

	}
}
void solve() {
	BFS();
	int ans = 987654321;
	for (int i = 0; i <= H + 1; i++) {
		for (int j = 0; j <= W + 1; j++) {
			if (map[i][j] != '*') {
				int tmp = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
				if (map[i][j] == '#')
					tmp -= 2;
				ans = min(ans, tmp);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		int idx = 0;
		cin >> H >> W;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					person[idx][0] = i;
					person[idx++][1] = j;
					map[i][j] = '.';
				}
			}
		}
		person[2][0] = person[2][1] = 0;
		solve();
	}
}