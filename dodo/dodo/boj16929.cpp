#include<iostream>
#include<vector>
using namespace std;

int N,M;
char map[51][51];
int visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int stx;
int sty;
bool flag = false;
vector<pair<int, int>> v;
void DFS(int x,int y,char c,int cnt) {
	if (flag)
		return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
			if (map[ny][nx] == c) {
				if (cnt >= 4) {
					if (stx == nx&&sty == ny) {
						flag = true;
						return;
					}
				}
				if (visit[ny][nx] == 0) {
					visit[ny][nx] = 1;
					DFS(nx, ny, c, cnt + 1);
					visit[ny][nx] = 0;
				}
			}
		}
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				stx = j;
				sty = i;
				visit[i][j] = 1;
				DFS(j, i, map[i][j], 1);
				visit[i][j] = 0;
			}
			if (flag == true)
				return;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	if (flag)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}