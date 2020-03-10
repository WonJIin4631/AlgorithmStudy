#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
/*
치즈 격자에서 외부와 접촉한 칸이 2개이상이면 녹는다.
1시간 간격으로 녹는게 진행된다.
치즈내부에 빈 곳이 있으면 그것은 외부 공기가아니다.


2차원 배열 치즈의 상태, 외부공기인지 판별할 맵, 접촉횟수 맵, 방문했는지 확인 맵
주어진 행,열 높이 외에는 외부공기이다.
외부공기를 BFS로 탐색하며 상하좌우에 접촉횟수를 더한다.
치즈의 상태에서 외부공기가 아니며,치즈의 부분일대 치즈부분이 접촉횟수가 2이상이면 녹인다.
*/
int map[106][106] = { 0 };
bool visit[106][106] = { 0 };
int cMap[104][104] = { 0 };
int N, M;
typedef pair<int, int> pii;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
int check_air() {
	int cnt = 0;
	queue <pii> q;
	q.push(pii(0, 0));
	visit[0][0] = true;
	while (!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= M+ 1 && ny >= 0 && ny <= N + 1) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] == 0) {
						visit[ny][nx] = true;
						q.push(pii(ny, nx));
						//4방향 공기접촉
						for (int k = 0; k < 4; k++) {
							int nnx = nx + dx[k];
							int nny = ny + dy[k];
							if (nnx >= 0 && nnx <= M + 1 && nny >= 0 && nny <= N + 1) {
								if(map[nny][nnx]==1)
									cMap[nny][nnx]++;
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}
void melt() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			//치즈조각일때
			if (map[i][j] == 1) {
				//접촉횟수 2개이상일때
				if (cMap[i][j] >= 2) {
					map[i][j] = 0;
				}
			}
		}
	}
}
void solve() {
	int time = 0;
	while (true){
		int cnt = check_air();
		if (cnt == (N + 2)*(M + 2)) {
			ans = time;
			break;
		}
		melt();
		memset(visit, false, sizeof(visit));
		memset(cMap, 0, sizeof(cMap));
		time++;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}