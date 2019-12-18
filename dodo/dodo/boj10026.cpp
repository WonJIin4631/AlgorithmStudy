#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int ans = 0;
int ans2 = 0;
int N;
char map[101][101];
int visit[101][101];
int visit2[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

queue<pair<int, int>> q;

void BFS(int cx,int cy,char color,char ord) {
	q.push(make_pair(cx, cy));
	if (ord == 'Y') {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (visit[ny][nx] == 0) {
						if (color == 'B') {
							if (map[ny][nx] == 'B') {
								visit[ny][nx] = 1;
								q.push(make_pair(nx, ny));
							}
						}
						else {
							if (map[ny][nx] == 'R' || map[ny][nx] == 'G') {
								visit[ny][nx] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	else {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (visit2[ny][nx] == 0) {
						if (color == 'B') {
							if (map[ny][nx] == 'B') {
								visit2[ny][nx] = 1;
								q.push(make_pair(nx, ny));
							}
						}
						else if (color == 'G') {
							if (map[ny][nx] == 'G') {
								visit2[ny][nx] = 1;
								q.push(make_pair(nx, ny));
							}
						}
						else {
							if (map[ny][nx] == 'R') {
								visit2[ny][nx] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				ans2++;
				visit[i][j] = 1;
				BFS(j, i,map[i][j],'Y');
			}
			if (visit2[i][j] == 0) {
				ans++;
				visit2[i][j] = 1;
				BFS(j, i, map[i][j], 'N');
			}
		}
	}
	cout<<ans<<' ' << ans2 << '\n';
}