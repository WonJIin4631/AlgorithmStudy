#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N, L, R;
int map[51][51];
bool visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
struct Info{
	int x;
	int y;
};
void init() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
bool BFS(int x,int y) {
	queue<Info> q;
	q.push({ x,y });
	vector<Info> v;
	v.push_back({ x,y });
	int sum = map[y][x];
	while (!q.empty()){
		Info cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx >= 0 &&nx < N&&ny >= 0 && ny < N) {
				if (!visit[ny][nx]) {
					int sub = abs(map[cur.y][cur.x] - map[ny][nx]);
					if (sub >= L&&sub <= R) {
						visit[ny][nx] = true;
						sum += map[ny][nx];
						v.push_back({ nx,ny });
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	bool flag = false;
	if (v.size() > 1) {
		int val = sum / v.size();
		for (int i = 0; i < v.size(); i++) {
			map[v[i].y][v[i].x] = val;
		}
		flag = true;
	}
	v.clear();

	return flag;
}
bool check() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				if (BFS(j, i)) {
					flag = true;
				}
			}
		}
	}
	return flag;
}
void solve() {
	init();
	while (true) {
		if (!check()) {
			break;
		}
		ans++;
		memset(visit, false, sizeof(visit));
	}
	cout << ans << '\n';
}
int main() {
	solve();
	return 0;
}