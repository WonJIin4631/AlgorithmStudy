#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


struct Info {
	int x;
	int y;
};
int N, M;
queue<Info> q;
int map[51][51];
bool visit[51][51] = { 0 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int ans = 0;
bool isIn(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
int BFS(int x, int y) {
	int dist = 0;
	bool flag = false;
	visit[y][x] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int qsz = q.size();
		for (int ss = 0; ss < qsz; ss++) {
			Info cur = q.front();
			q.pop();
			if (map[cur.y][cur.x]) {
				flag = true;
			}
			if (flag)
				continue;
			for (int d = 0; d < 8; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny)) {
					if (!visit[ny][nx]) {
						visit[ny][nx] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		if(!flag)
			dist++;
	}
	return dist;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				int temp = BFS(j, i);
				ans = max(temp, ans);
				memset(visit, 0, sizeof(visit));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}