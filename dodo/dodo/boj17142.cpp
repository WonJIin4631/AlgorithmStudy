#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
int map[51][51];
bool visit[51][51];
typedef pair<int, int> pii;
vector<pii> virus;
int virusCnt = 0;
bool virusCheck[11] = { 0 };
int leftCnt = 0;
int ans = 987654321;

int dx[] = { 0,0,-1,1};
int dy[] = { -1,1,0,0 };

int v_move() {
	queue<pii> q;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < virusCnt; i++) {
		if (virusCheck[i]) {
			q.push(virus[i]);
			visit[virus[i].first][virus[i].second]=true;
		}
	}
	int tempCnt = leftCnt;
	int time = 0;
	while (!q.empty()) {
		if (tempCnt == 0)
			break;
		int qsz = q.size();
		for (int tt = 0; tt < qsz; tt++ ) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (visit[ny][nx] == false) {
						if (map[ny][nx] == 0) {
							visit[ny][nx] = true;
							tempCnt--;
							q.push(pii(ny, nx));
						}
						else if (map[ny][nx] == 2) {
							visit[ny][nx] = true;
							q.push(pii(ny, nx));
						}
					}
				}
			}
		}
		time++;
	}
	if (tempCnt == 0)
		return time;
	return 987654321;
}
void DFS(int cnt,int idx) {
	if (cnt == M) {
		ans = min(ans,v_move());
		return;
	}
	for (int i = idx; i < virusCnt; i++) {
		if (virusCheck[i] == false) {
			virusCheck[i] = true;
			DFS(cnt + 1, i);
			virusCheck[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				leftCnt++;
			}
			else if (map[i][j] == 2) {
				virusCnt++;
				virus.push_back(pii(i, j));
			}
		}
	}
	DFS(0,0);
	if (ans == 987654321)
		ans = -1;
	cout << ans << '\n';
	return 0;
}