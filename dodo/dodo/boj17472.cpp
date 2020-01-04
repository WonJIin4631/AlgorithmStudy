#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#define INF 987654321
typedef pair<int, int > pii;


int N, M;
int map[11][11];
int visit[11][11];
int island_Cnt = 0;
vector<pair<int, int>> island[7];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int distIsland[6][6];
int check[7];
int ans = INF;
/*
섬의개수 최대 6개
*/
queue<pair<int, int>> q;


void prim(int n) {

	for (int i = 1; i <= island_Cnt; i++) {
		for (int j = 1; j <= island_Cnt; j++) {
			cout << distIsland[i][j] << ' ';
		}
		cout << '\n';
	}
	check[n] = 1;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 1; i <= island_Cnt; i++) {
		if (distIsland[n][i] != INF) {
			pq.push(pii(distIsland[n][i],i ));
		}
	}
	int val = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (check[cur] == 1)
			continue;
		check[cur] = 1;
		val += cost;
		for (int i = 1; i <= island_Cnt; i++) {
			if (distIsland[cur][i] != INF) {
				int next = i;
				int nextcost = distIsland[cur][i];
				pq.push(pii(nextcost, next));
			}
		}
	}
	bool flag = true;
	for (int i = 1; i <= island_Cnt; i++) {
		if (check[i] == 0) {
			flag = false;
		}
		cout << check[i] << ' ';
	}
	if (val != 0 && flag)
		ans = min(ans, val);
}

void connect() {
	for (int i = 1; i <= island_Cnt; i++) {
		for (int j = 0; j < island[i].size(); j++) {
			int x = island[i][j].second;
			int y = island[i][j].first;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x;
				int ny = y;
				int dist = 0;
				while (true) {
					nx += dx[dir];
					ny += dy[dir];
					if (nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] == i)
						break;
					if (map[ny][nx] != 0 && map[ny][nx] != i) {
						if (dist > 1) {
							int to = map[ny][nx];
							distIsland[i][to] = min(distIsland[i][to], dist);
							distIsland[to][i] = min(distIsland[to][i], dist);
							break;
						}
						if (dist == 1)
							break;
					}
					dist++;
				}
			}
		}
	}
}
void BFS(int num) {
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		map[y][x] = num;
		q.pop();
		//주변에 물이있는지 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M&&ny < N) {
				if (map[ny][nx] == 0) {
					island[num].push_back(make_pair(y, x));
					break;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[ny][nx] == 0) {
				if (nx >= 0 && ny >= 0 && nx < M&&ny < N) {
					if (map[ny][nx] == 1) {
						q.push(make_pair(ny, nx));
						visit[ny][nx] = 1;
					}
				}
			}
		}
	}
}
void divIsland() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				if (map[i][j] == 1) {
					q.push(make_pair(i, j));
					visit[i][j] = 1;
					island_Cnt++;
					BFS(island_Cnt);
				}
			}
		}
	}
}

void solve() {
	divIsland();
	connect();

	cout << island_Cnt << '\n';
	prim(1);
	if (ans != INF)
		cout << ans << '\n';
	else
		cout << -1 << '\n';
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			distIsland[i][j] = INF;
		}
	}
	solve();
	return 0;
}