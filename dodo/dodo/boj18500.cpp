#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

/*
왼쪽 오른쪽 번갈아가면서 막대를 던지면서 미네랄을 파괴
파괴된 이후 클러스터가 분리되면 중력으로 인해 바닥으로 떨어진다.(땅을 만나거나 다른 클러스터 위에 떨어지고 합쳐진다)

1. 입력
2. 막대 던지기(왼쪽 ,오른쪽 반복),미네랄 파괴
3. 클러스터 분리됬는지 확인 분리되면 4번 아니면 2번 /BFS로 클러스터가 1개인지 확인 -> 미네랄이 한번에 탐색가능하면 1덩이 아니면 분리 되어있음
4. 분리되었으면 중력 발생 2번으로 이동 / 위에서부터 다시 탐색해서 나온 클러스터가 위에 떠있는 미네랄이다. 이 클러스터에서 아래방향으로 최소 칸을 확인 ( 이때 같은 클러스터의 미네랄이 아닌것을 확인해야한다)
*/
struct Info {
	int x;
	int y;
};
char map[101][101];
int visit[101][101];
int R, C, N;
int stick[101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<Info> cluster;
int clusterNum = 0;
bool isIn(int x, int y) {
	return x >= 0 && x < C&&y >= 0 && y < R;
}
void move_cluster() {
	int dist = 987654321;
	for (int i = 0; i < cluster.size(); i++) {
		int temp = 0;
		int x = cluster[i].x;
		for (int y = cluster[i].y + 1; y < R; y++) {
			if (map[y][x] == 'x') {
				if (visit[y][x] == clusterNum) {
					temp = 987654321;
				}
				break;
			}
			temp++;
		}
		if (temp > 0) {
			dist = min(dist, temp);
		}
	}
	for (int i = 0; i < cluster.size(); i++) {
		int x = cluster[i].x;
		int y = cluster[i].y;
		map[y][x] = '.';
	}
	for (int i = 0; i < cluster.size(); i++) {
		int x = cluster[i].x;
		int y = cluster[i].y;
		map[y + dist][x] = 'x';
	}
}
void check_cluster() {
	int cnt = 0;
	queue<Info> q;
	bool flag = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'x') {
				if (visit[i][j] == 0) {
					cnt++;
					bool check_cluster = false;
					q.push({ j,i });
					visit[i][j] = cnt;
					//BFS
					while (!q.empty()) {
						Info cur = q.front();
						if (!flag) {
							cluster.push_back({ cur.x,cur.y });
						}
						q.pop();
						if (cur.y == R - 1)
							check_cluster = true;
						for (int d = 0; d < 4; d++) {
							int nx = cur.x + dx[d];
							int ny = cur.y + dy[d];
							if (isIn(nx, ny)) {
								if (map[ny][nx] == 'x') {
									if (visit[ny][nx] == 0) {
										visit[ny][nx] = cnt;
										q.push({ nx,ny });
									}
								}
							}
						}
					}
					if (!flag) {
						if (check_cluster) {
							cluster.clear();
						}
						else {
							flag = true;
							clusterNum = cnt;
						}
					}
				}
			}
		}
	}
}
void throw_stick(int d, int idx) {
	int h = R - stick[idx];
	if (d == 1) {
		for (int i = 0; i < C; i++) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = C - 1; i >= 0; i--) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				break;
			}
		}
	}
}
void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stick[i];
	}
}
void solve() {
	init();
	int d = 1;
	for (int i = 0; i < N; i++) {
		throw_stick(d, i);
		d *= -1;
		check_cluster();
		if (cluster.size() != 0)
			move_cluster();
		memset(visit, 0, sizeof(visit));
		cluster.clear();
	}
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << map[y][x];
		}
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}