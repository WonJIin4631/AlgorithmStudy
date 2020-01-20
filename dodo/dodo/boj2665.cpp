#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<functional>
using namespace std;
#define INF 987654321
int N;
string map[51];
int visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
typedef pair<int, pair<int, int>> piii;
bool comp(piii a, piii b) {
	return a.first < b.first;
}
void solve() {
	queue<piii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = INF;
		}
	}
	q.push(make_pair(0, make_pair(0, 0)));
	visit[0][0] = -1;
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == N - 1) {	
			ans = min(cnt,ans);
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N&&nx >= 0 && nx < N) {
				if (map[ny][nx] == '1') {
					if (visit[ny][nx] > cnt) {
						visit[ny][nx] = cnt;
						q.push(make_pair(cnt, make_pair(nx, ny)));
					}
				}
				if (map[ny][nx] == '0') {
					if (visit[ny][nx] > cnt+1) {
						visit[ny][nx] = cnt+1;
						q.push(make_pair(cnt+1, make_pair(nx, ny)));
					}
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	solve();
	cout << ans << '\n';
	
	return 0;
}