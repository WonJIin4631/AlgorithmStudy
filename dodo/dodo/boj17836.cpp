#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, T;
int map[101][101];
int visit[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

pair<int, int> sword;
int get_sword=987654321;
int ans=987654321;
void BFS() {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	visit[0][0] = 1;
	while (!q.empty()){
		int x = q.front().second.second;
		int y = q.front().second.first;
		int time = q.front().first;
		q.pop();
		if (time >= T)
			return;
		if (y == N - 1 && x == M - 1) {
			if(ans>time)
				ans = time;
		}
		if (y == sword.first && x == sword.second) {
			if(get_sword>time)
				get_sword = time;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M&&ny < N) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] != 1) {
						q.push(make_pair(time + 1, make_pair(ny, nx)));
						visit[ny][nx] = 1;
					}
				}
			}
		}
	}
}
void solve() {
	BFS();
	int swtogonju = abs(N - sword.first-1) + abs(M - sword.second-1);
	ans = min(ans, get_sword + swtogonju);
	if (ans > T)
		cout << "Fail" << '\n';
	else
		cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sword = { i,j };
			}
		}
	}
	solve();
	return 0;
}	