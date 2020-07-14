#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Info {
	int x;
	int y;
	int idx;
};
int map[202][202];
int N, K, S, X, Y;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<Info> q;
vector<Info> virus[1002];
bool Isin(int x, int y) {
	return x >= 1 && x <= N&&y >= 1 && y <= N;
}
int main() {
	cin >> N >> K;
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				virus[map[i][j]].push_back({ j,i,map[i][j] });
			}
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < virus[i].size(); j++) {
			q.push(virus[i][j]);
		}
	}
	cin >> S >> Y >> X;
	int time = 0;
	while (!q.empty()) {
		int qsz = q.size();
		if (time == S)
			break;
		for (int i = 0; i < qsz; i++) {
			Info cur = q.front();
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (Isin(nx, ny)) {
					if (map[ny][nx] == 0) {
						map[ny][nx] = cur.idx;
						q.push({ nx,ny,cur.idx });
					}
				}
			}
		}
		time++;
	}
	cout << map[Y][X] << '\n';
	return 0;
}