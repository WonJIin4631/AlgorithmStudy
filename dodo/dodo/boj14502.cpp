#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int map[9][9];
int N, M;
int anjeon = 0;
int ans = 0;
vector<pair<int, int>> v;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int visit[9][9];
int BFS() {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		q.push(make_pair(v[i].first, v[i].second));
	}
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0 && visit[ny][nx]==0) {
					visit[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					cnt++;
				}
			}
		}
	}
	return cnt;
}
void DFS(int idx,int x,int y) {
	if (idx == 3) {
		int cnt=BFS();
		if (ans < (anjeon - 3 - cnt))
			ans = anjeon - 3 - cnt;
		return;
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				DFS(idx + 1,x,y);
				map[i][j] = 0;
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
				v.push_back(make_pair(i, j));
			else if (map[i][j] == 0)
				anjeon++;
		}
	}
	DFS(0,0,0);
	cout << ans << '\n';
}