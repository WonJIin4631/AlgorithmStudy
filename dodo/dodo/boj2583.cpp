#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, K;
int map[101][101] = { 0 };
int visit[101][101] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<int> ans;
void make_rect(int lx,int ly,int rx,int ry) {
	for (int i = ry; i < ly; i++) {
		for (int j = lx; j < rx; j++) {
			map[i][j] = 1;
		}
	}
}
void BFS(int y,int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;
	int cnt = 0;
	while (!q.empty()){
		cnt++;
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (visit[ny][nx] == 0&&map[ny][nx]==0) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
				}
			}
		}
	}
	ans.push_back(cnt);
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		make_rect(lx, N  - ly, rx, N  - ry);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0)
				BFS(i, j);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}