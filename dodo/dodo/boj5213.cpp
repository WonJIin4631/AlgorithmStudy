#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int map[502][1002] = { 0 };
bool visit[502][1002] = { 0 };
int prevIdx[249751] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
struct Info {
	int x; int y;
};
bool isIn(int x, int y) {
	if (y % 2 == 0) {
		if (x == 1 || x == N * 2)
			return false;
	}
	return x >= 1 && x <= N * 2 && y >= 1 && y <= N;
}
bool checkSameTile(int x, int y, int nx, int ny) {
	int minX = min(x, nx);
	if (y == ny) {
		if (y % 2 == 0) {
			if (minX % 2 == 0)
				return true;
		}
		else {
			if (minX % 2 == 1)
				return true;
		}
	}
	return false;
}
int getTileIdx(int x, int y) {
	int idx = 0;
	for (int i = 1; i < y; i++) {
		if (i % 2 == 0)
			idx += N - 1;
		else
			idx += N;
	}
	if (y % 2 == 0) {
		idx += x / 2;
	}
	else {
		for (int i = 0; i < x; i += 2) {
			idx++;
		}
	}
	return idx;
}
void init() {
	cin >> N;
	int l, r;
	int h = 1, w = 1;
	for (int i = 0; i < (N*N) - (N / 2); i++) {
		cin >> l >> r;
		map[h][w++] = l;
		map[h][w++] = r;
		if (h % 2 == 1) {
			if (w == N * 2 + 1) {
				h++;
				w = 2;
			}
		}
		else {
			if (w == N * 2) {
				h++;
				w = 1;
			}
		}
	}
}

void moveStart() {
	queue<Info> q;
	prevIdx[1] = 1;
	visit[1][1] = true;
	q.push({ 1,1 });
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		int cIdx = getTileIdx(cur.x, cur.y);
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (isIn(nx, ny)) {
				if (checkSameTile(cur.x, cur.y, nx, ny)) {
					if (visit[ny][nx] == false) {
						visit[ny][nx] = true;
						q.push({ nx, ny });
					}
				}
				else {
					if (map[cur.y][cur.x] == map[ny][nx]) {
						int nIdx = getTileIdx(nx, ny);
						if (prevIdx[nIdx] == 0) {
							prevIdx[nIdx] = cIdx;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}
void show() {
	vector<int> ans;
	bool flag = false;
	for (int i = (N*N) - (N / 2); i >= 1; i--) {
		if (prevIdx[i] != 0) {
			int cur = i;
			flag = true;
			while (cur!=1){
				ans.push_back(cur);
				cur = prevIdx[cur];
			}
		}
		if (flag)
			break;
	}
	ans.push_back(1);
	cout << ans.size() << '\n';
	for (int i = ans.size()-1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	moveStart();
	show();
	return 0;
}