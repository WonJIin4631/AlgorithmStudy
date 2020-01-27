#include<iostream>
#include<algorithm>
using namespace std;

int map[11][11];
int N, M, K;
int visit[11][11] = { 0 };
int ans = -1e9;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void DFS(int x,int y,int cnt,int sum) {
	if (cnt == K) {
		ans = max(sum, ans);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				bool flag = true;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
						if (visit[ny][nx]==1)
							flag = false;
					}
				}
				if (flag) {
					visit[i][j] = 1;
					DFS(j, i, cnt + 1, sum + map[i][j]);
					visit[i][j] = 0;
				}
			}
		}
	}
}
int main() {
	cin >> N>> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	DFS(0, 0, 0, 0);
	cout << ans << '\n';
	return 0;
}