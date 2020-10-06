#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Info {
	int x;
	int y;
	int time;
	bool get_sword;
};
struct comp {
	bool operator()(Info a, Info b) {
		return a.time > b.time;
	}
};
int map[101][101];
bool visit[2][101][101];
int N, M, T;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
bool Isin(int x, int y) {
	return x >= 0 && x < M&&y >= 0 && y < N;
}
int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	priority_queue<Info, vector<Info>, comp> pq;
	if (map[0][0] == 0)
		pq.push({ 0,0,0,0 });
	else
		pq.push({ 0,0,0,1 });
	visit[0][0][0] = true;
	while (!pq.empty()) {
		Info cur = pq.top();
		pq.pop();
		if (cur.x == M - 1 && cur.y == N - 1) {
			ans = cur.time;
			break;
		}
		if (cur.time > T)
			continue;
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (Isin(nx, ny)) {
				if (visit[cur.get_sword][ny][nx] == false) {
					if (map[ny][nx] == 0) {
						visit[cur.get_sword][ny][nx] = true;
						pq.push({ nx,ny,cur.time + 1,cur.get_sword });
					}
					else if (map[ny][nx] == 1) {
						if (cur.get_sword == true) {
							visit[cur.get_sword][ny][nx] = true;
							pq.push({ nx,ny,cur.time + 1,cur.get_sword });
						}
					}
					else {
						visit[0][ny][nx] = true;
						visit[1][ny][nx] = true;
						pq.push({ nx,ny,cur.time + 1,true });
					}
				}
			}
		}
	}
	if (ans == 987654321)
		cout << "Fail" << '\n';
	else
		cout << ans << '\n';
	return 0;
}