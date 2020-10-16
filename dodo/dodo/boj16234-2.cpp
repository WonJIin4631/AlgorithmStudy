#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct Info{
	int x;
	int y;
};
int map[51][51] = { 0 };
int idxMap[51][51] = { 0 };
int cityCnt[2501] = { 0 };
int citySum[2501] = { 0 };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, L, R;
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
void init() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
int searchCity(int x,int y,int idx) {
	queue<Info> q;
	q.push({ x,y });
	idxMap[y][x] = idx;
	cityCnt[idx] = 1;
	citySum[idx] = map[y][x];
	while (!q.empty()){
		Info cur = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (isIn(nx, ny)) {
				if (idxMap[ny][nx] == 0) {
					int diff = abs(map[cur.y][cur.x] - map[ny][nx]);
					if (diff >= L&&diff <= R) {
						cityCnt[idx]++;
						citySum[idx] += map[ny][nx];
						idxMap[ny][nx] = idx;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return cityCnt[idx];
}
bool cityOpen() {
	int idx = 1;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (idxMap[i][j] == 0) {
				int connectedCityCnt = searchCity(j, i, idx);
				if (connectedCityCnt > 1)
					flag = true;
				idx++;
			}
		}
	}
	return flag;
}
void cityMove() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int curIdx = idxMap[i][j];
			idxMap[i][j] = 0;
			map[i][j] = (citySum[curIdx] / cityCnt[curIdx]);
		}
	}
}
void solve() {
	init();
	int ans = 0;
	while (true){
		if (!cityOpen())
			break;
		cityMove();
		ans++;
	}
	cout << ans << '\n';
}
int main() {
	solve();
	return 0;
}