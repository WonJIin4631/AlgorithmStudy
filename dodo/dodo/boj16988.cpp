#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int map[21][21];
int visit[21][21];
int visit2[21][21];
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;

int BFS(int x,int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit2[y][x] = 1;
	int cnt = 0;
	bool flag = true;
	while (!q.empty()){
		cnt++;
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (visit2[ny][nx] == 0) {
					if (map[ny][nx] == 2) {
						visit2[ny][nx] = 1;
						q.push(make_pair(nx, ny));
					}
				}
				if (map[ny][nx] == 0) {
					flag = false;
				}
			}
		}
	}
	if (flag) {
		return cnt;
	}
	else {
		return 0;
	}
}
void DFS(int x,int y,int cnt) {
	if (cnt == 2) {
		memset(visit2, 0, sizeof(visit2));
		int val = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 2) {
					if (visit2[i][j] == 0) {
						val+=BFS(j, i);
					}
				}
			}
		}
		if (ans < val)
			ans = val;
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					visit[i][j] = 1;
					DFS(j, i, cnt + 1);
					visit[i][j] = 0;
					map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	DFS(0, 0, 0);
	cout << ans << '\n';
}