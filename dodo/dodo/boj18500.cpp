#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

/*
���� ������ �����ư��鼭 ���븦 �����鼭 �̳׶��� �ı�
�ı��� ���� Ŭ�����Ͱ� �и��Ǹ� �߷����� ���� �ٴ����� ��������.(���� �����ų� �ٸ� Ŭ������ ���� �������� ��������)

1. �Է�
2. ���� ������(���� ,������ �ݺ�),�̳׶� �ı�
3. Ŭ������ �и������ Ȯ�� �и��Ǹ� 4�� �ƴϸ� 2�� /BFS�� Ŭ�����Ͱ� 1������ Ȯ�� -> �̳׶��� �ѹ��� Ž�������ϸ� 1���� �ƴϸ� �и� �Ǿ�����
4. �и��Ǿ����� �߷� �߻� 2������ �̵� / ���������� �ٽ� Ž���ؼ� ���� Ŭ�����Ͱ� ���� ���ִ� �̳׶��̴�. �� Ŭ�����Ϳ��� �Ʒ��������� �ּ� ĭ�� Ȯ�� ( �̶� ���� Ŭ�������� �̳׶��� �ƴѰ��� Ȯ���ؾ��Ѵ�)
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