#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int map[51][51];
int N, M;
typedef pair<int, int> pii;
vector<pii> v;
bool check[15] = { 0 };
bool visit[51][51] = { 0 };
int homeCnt = 0;
int ans = 987654321;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int get_dist() {
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	for (int i = 0; i < v.size(); i++) {
		if (check[i] == 0) {
			visit[v[i].first][v[i].second] = 1;
			q.push(v[i]);
		}
	}
	int tempCnt = homeCnt;
	int dist = 0;
	int sum = 0;
	while (!q.empty()) {
		if (tempCnt == 0)
			break;
		dist++;
		int qsz = q.size();
		for (int t = 0; t < qsz; t++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						q.push(pii(ny, nx));
						if (map[ny][nx] == 1) {
							tempCnt--;
							sum += dist;
						}
					}
				}
			}
		}
	}
	return sum;
}

void DFS(int cnt,int idx) {
	if (cnt == M) {
		ans = min(ans, get_dist());
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (check[i] == false) {
			check[i] = true;
			DFS(cnt - 1,i+1);
			check[i] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				homeCnt++;
			else if (map[i][j] == 2)
				v.push_back(pii(i, j));
		}
	}
	DFS(v.size(),0);
	cout << ans << '\n';
	return 0;
}