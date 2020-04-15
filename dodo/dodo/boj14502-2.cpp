#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int map[9][9] = { 0 };
int visit[9][9] = { 0 };
bool check[9][9] = { 0 };
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
typedef pair<int, int> pii;
vector <pii> v;
int leftCan = 0;
int ans = 0;

int spread() {
	queue<pii> q;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		visit[v[i].first][v[i].second] = 1;
	}
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0) {
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						cnt++;
						q.push(pii(ny, nx));
					}
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	return cnt;
}
void solve(int idx, int cnt) {
	if (cnt == 3) {
		int temp = spread();
		ans = max(ans, leftCan - temp - 3);
		return;
	}
	for (int i = idx; i < N*M; i++) {
		int y = i / M;
		int x = i % M;
		if (map[y][x] == 0) {
			if (check[y][x] == 0) {
				check[y][x] = 1;
				map[y][x] = 1;
				solve(i + 1, cnt + 1);
				check[y][x] = 0;
				map[y][x] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				v.push_back(pii(i, j));
			else if (map[i][j] == 0)
				leftCan++;
		}
	}
	solve(0, 0);
	cout << ans << '\n';
	return 0;
}