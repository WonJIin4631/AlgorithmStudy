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
int distIsland[7][7];
int check[7];
int ans = INF;
int parent[7];
/*
섬의개수 최대 6개
*/
queue<pair<int, int>> q;


int find(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return find(parent[n]);
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}
void get_ans(int idx, int sum, int cnt) {
	bool flag = true;
	for (int i = 1; i <= island_Cnt; i++) {
		if (check[i] == 0) {
			flag = false;
			break;
		}
	}
	if (flag) {
		ans = min(sum, ans);
		return;
	}
	else {

		for (int i = 1; i <= island_Cnt; i++) {
			if (check[i] == 0) {
				if (distIsland[idx][i] != INF) {
					check[i] = 1;
					get_ans(i, sum + distIsland[idx][i], cnt + 1);
					check[i] = 0;
				}
			}
		}
	}
}
void get_Dist() {
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= island_Cnt; i++) {
		for (int j = 1; j <= island_Cnt; j++) {
			cout << distIsland[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	vector<pair<int, pair<int, int>>> info;
	for (int i = 1; i <= island_Cnt; i++) {
		for (int j = 1; j <= island_Cnt; j++) {
			if (distIsland[i][j] != INF) {
				info.push_back(make_pair(distIsland[i][j], make_pair(i, j)));
			}
		}
	}
	sort(info.begin(), info.end());
	for (int i = 1; i < island_Cnt; i++) {
		parent[i] = i;
	}
	int val = 0;
	for (int i = 1; i <= 2; i++) {
		for (int j = 0; j < info.size(); j++) {
			int from = info[j].second.first;
			int to = info[j].second.second;
			if (find(from) != find(to)) {
				merge(from, to);
				if (i == 1) {
					val += info[j].first;
				}
			}
		}
	}
	int a = parent[1];
	bool flag = true;
	for (int i = 2; i <= island_Cnt; i++) {
		int b = find(i);
		if (a != b) {
			flag = false;
			break;
		}
	}
	for (int i = 1; i <= island_Cnt; i++) {
		cout << parent[i] << '\n';
	}
	if (flag) {
		cout << val << '\n';
	}
	else {
		cout << -1 << '\n';
	}
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

	get_Dist();

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			distIsland[i][j] = INF;
		}
	}
	solve();
	return 0;
}