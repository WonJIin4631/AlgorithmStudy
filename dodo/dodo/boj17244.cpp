#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
/*
모든 물건을 챙기고 나가기 까지 시간이 최소인것을 출력
물건이 최대 5개 
현재 위치에서 물건위치와 입구까지 거리찾기
물건 기준으로 각자의 거리 찾기
DFS로 모든 경우를 찾아 최소값 출력

*/
int map[52][52] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int sx, sy;
int N, M;
int visit[52][52] = { 0 };

int stuff[8] = { 0 };
typedef pair<int, int> pii;
pii info[8];
int dist[9][9] = { 0 };
int stf_cnt = 0;
int ans = 987654321;
void DFS(int cur,int sum,int cnt) {
	if (cnt == stf_cnt) {
		ans = min(ans, sum + dist[cur][stf_cnt + 1]);
		return;
	}
	for (int i = 1; i <= stf_cnt; i++) {
		if (stuff[i] == 0) {
			stuff[i] = 1;
			DFS(i, sum + dist[cur][i], cnt + 1);
			stuff[i] = 0;
		}
	}
}
void find_dist() {
	queue<pair<int, pii>> q;
	//시작점에서 탐색
	q.push(make_pair(0, pii(sy, sx)));
	visit[sy][sx] = 1;
	while (!q.empty()) {
		int x = q.front().second.second;
		int y = q.front().second.first;
		int d = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] != -1) {
						visit[ny][nx] = 1;
						if (map[ny][nx] > 0&&map[ny][nx]<6) {
							dist[0][map[ny][nx]] = d + 1;
							dist[map[ny][nx]][0] = d + 1;
						}
						else if (map[ny][nx] == 10) {
							dist[0][stf_cnt + 1] = d + 1;
							dist[stf_cnt + 1][0] = d + 1;
						}
						q.push(make_pair(d + 1, pii(ny, nx)));
					}
				}
			}
		}
	}
	// 나머지 물건들 위치에서 탐색
	for (int i = 1; i <= stf_cnt; i++) {
		memset(visit, 0, sizeof(visit));
		visit[info[i].first][info[i].second] = 1;
		q.push(make_pair(0, pii(info[i].first, info[i].second)));
		while (!q.empty()){
			int x = q.front().second.second;
			int y = q.front().second.first;
			int d = q.front().first;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
					if (visit[ny][nx] == 0) {
						if (map[ny][nx] != -1) {
							visit[ny][nx] = 1;
							if (map[ny][nx] > 0 && map[ny][nx]<6) {
								dist[i][map[ny][nx]] = d + 1;
								dist[map[ny][nx]][i] = d + 1;
							}
							else if (map[ny][nx] == 10) {
								dist[i][stf_cnt + 1] = d + 1;
								dist[stf_cnt + 1][i] = d + 1;
							}
							q.push(make_pair(d + 1, pii(ny, nx)));
						}
					}
				}
			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == '#')
				map[i][j] = -1;
			else if (c == 'E')
				map[i][j] = 10;
			else if (c == 'S')
				sx = j, sy = i;
			else if (c == 'X') {
				stf_cnt++;
				info[stf_cnt] = pii(i, j);
				map[i][j] = stf_cnt;
			}
		}
	}
	find_dist();
	DFS(0,0,0);
	cout << ans << '\n';
	return 0;
}