#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char map[1001][1001];
bool visit[1001][1001];
int timeMap[1001][1001] = { 0 };
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
typedef pair<int, int> pii;
pii st;
queue<pii> q;
int solve() {

	if (q.empty()){
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
				timeMap[i][j] = 987654321;
	}
	else {
		//불부터 움직임

		while (!q.empty()) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
					if (map[ny][nx] == '.') {
						if (visit[ny][nx] == 0) {	
							visit[ny][nx] = 1;
							timeMap[ny][nx] = timeMap[y][x] + 1;
							q.push(pii(ny, nx));
						}
					}
				}
			}

		}
		memset(visit, 0, sizeof(visit));
	}
	//지훈이 움직임
	q.push(st);
	visit[st.first][st.second] = 1;
	int time = 0;
	while (!q.empty()) {
		int qsz = q.size();
		for (int sz = 0; sz < qsz; sz++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			if (timeMap[y][x] <= time)
				continue;
			if (x == 0 || x == M - 1 || y == 0 || y == N - 1) {
				return time;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
					if (map[ny][nx] == '.') {
						if (visit[ny][nx] == 0) {
							visit[ny][nx] = 1;
							q.push(pii(ny, nx));
						}
					}
				}
			}
		}
		time++;
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				map[i][j] = '.';
				st = pii(i, j);
			}
			if (map[i][j] == 'F') {
				q.push(pii(i, j));
				visit[i][j] = 1;
			}
		}
	}
	int ans = solve();
	if (ans == -1)
		cout << "IMPOSSIBLE" << '\n';
	else
		cout << ans + 1 << '\n';
	return 0;
}