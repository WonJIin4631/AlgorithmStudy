#include<iostream>
#include<algorithm>
using namespace std;

int map[101][101];
bool visit[101][101] = { 0 };
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
void solve(int idx,int sum) {
	if (idx == N*M) {
		
		ans = max(sum, ans);
		return;
	}
	int x = idx%M;
	int y = idx/M;
	if (x - 1 >= 0 && y + 1 <N) {
		if (visit[y][x] == 0 && visit[y + 1][x] == 0 && visit[y][x - 1] == 0) {
			visit[y][x] = 1;
			visit[y + 1][x] = 1;
			visit[y][x - 1] = 1;
			int temp = map[y][x] * 2 + map[y + 1][x] + map[y][x - 1];
			solve(idx + 1,sum+temp);
			visit[y][x] = 0;
			visit[y + 1][x] = 0;
			visit[y][x - 1] = 0;
		}
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (visit[y][x] == 0 && visit[y - 1][x] == 0 && visit[y][x - 1] == 0) {
			visit[y][x] = 1;
			visit[y - 1][x] = 1;
			visit[y][x - 1] = 1;
			int temp = map[y][x] * 2 + map[y - 1][x] + map[y][x - 1];
			solve(idx + 1,sum+temp);
			visit[y][x] = 0;
			visit[y - 1][x] = 0;
			visit[y][x - 1] = 0;
		}
	}
	if (x + 1 < M&&y - 1 >= 0) {
		if (visit[y][x] == 0 && visit[y - 1][x] == 0 && visit[y][x + 1] == 0) {
			visit[y][x] = 1;
			visit[y - 1][x] = 1;
			visit[y][x + 1] = 1;
			int temp = map[y][x] * 2 + map[y - 1][x] + map[y][x + 1];
			solve(idx + 1,sum+temp);
			visit[y][x] = 0;
			visit[y - 1][x] = 0;
			visit[y][x + 1] = 0;
		}
	}
	if (x + 1 < M&&y + 1 < N) {
		if (visit[y][x] == 0 && visit[y + 1][x] == 0 && visit[y][x + 1] == 0) {
			visit[y][x] = 1;
			visit[y + 1][x] = 1;
			visit[y][x + 1] = 1;
			int temp = map[y][x] * 2 + map[y + 1][x] + map[y][x + 1];
			solve(idx + 1,sum+temp);
			visit[y][x] = 0;
			visit[y + 1][x] = 0;
			visit[y][x + 1] = 0;
		}
	}
	solve(idx + 1,sum);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	solve(0,0);
	cout << ans << '\n';
	return 0;
}