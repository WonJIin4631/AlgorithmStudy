#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct Info{
	int x;
	int y;
};
int N, M;
Info virus[11];
bool checkVirus[11] = { 0 };
int virusCnt = 0;
int map[51][51];
bool visit[51][51];
int leftCan = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
void init() {
	cin >> N >> M;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus[idx++] = { j,i };
				virusCnt++;
			}
			if (map[i][j] == 0)
				leftCan++;
		}
	}
}
int spreadVirus() {
	int time = 0;
	queue<Info> q;
	for (int i = 0; i < virusCnt; i++) {
		if (checkVirus[i]) {
			q.push(virus[i]);
			visit[virus[i].y][virus[i].x] = true;
		}
	}
	int tempLeftCan = leftCan;
	while (!q.empty()){
		int qsz = q.size();
		if (tempLeftCan == 0)
			break;
		for (int t = 0; t < qsz; t++) {
			Info cur = q.front();
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny)) {
					if (visit[ny][nx] == false) {
						if (map[ny][nx] == 0) {
							tempLeftCan--;
							visit[ny][nx] = true;
							q.push({ nx,ny });
						}
						else if (map[ny][nx] == 2) {
							visit[ny][nx] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		time++;
	}
	while (!q.empty()){
		q.pop();
	}
	if (tempLeftCan != 0)
		time = 987654321;
	return time;
}
void chooseVirus(int idx, int cnt) {
	if (cnt == M) {
		memset(visit, 0, sizeof(visit));
		ans=min(ans,spreadVirus());
		return;
	}
	for (int i = idx; i < virusCnt; i++) {
		if (checkVirus[i] == false) {
			checkVirus[i] = true;
			chooseVirus(i + 1, cnt + 1);
			checkVirus[i] = false;
		}
	}
}
void solve() {
	chooseVirus(0, 0);
	if (ans == 987654321)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}
int main() {
	init();
	solve();
	return 0;
}