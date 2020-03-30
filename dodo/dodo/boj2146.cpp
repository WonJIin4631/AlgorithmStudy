#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
섬을 구분하며 섬의 외각부분의 좌표를 저장한다.
섬의 외각지역의 모든부분과 다른 섬의 외각지역의 거리를 계산


*/

int map[101][101];
int visit[101][101];
int N;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int island_cnt = 0;
typedef pair<int, int> pii;
vector<pii> island[10001];
int ans = 987654321;
void solve(int from, int to) {
	if (to != -1) {
		for (int i = 0; i < island[from].size(); i++) {
			for (int j = 0; j < island[to].size(); j++) {
				int dist = abs(island[from][i].first - island[to][j].first) + abs(island[from][i].second - island[to][j].second) - 1;
				ans = min(ans, dist);

			}
		}
		return;
	}
	for (int i = from + 1; i < island_cnt; i++) {
		solve(from, i);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	queue<pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				if (visit[i][j] == 0) {
					visit[i][j] = 1;
					q.push(pii(i, j));
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						bool flag = false;
						for (int k = 0; k < 4; k++) {
							int ny = y + dy[k];
							int nx = x + dx[k];
							if (ny >= 0 && ny < N&&nx >= 0 && nx < N) {
								if (map[ny][nx] == 1) {
									if (visit[ny][nx] == 0) {
										visit[ny][nx] = 1;
										q.push(pii(ny, nx));
									}
								}
								else {
									flag = true;
								}
							}
						}
						if (flag) {
							island[island_cnt].push_back(pii(y, x));
						}
					}
					island_cnt++;
				}
			}
		}
	}
	for (int i = 0; i < island_cnt; i++) {
		solve(i, -1);
	}
	cout << ans << '\n';
}