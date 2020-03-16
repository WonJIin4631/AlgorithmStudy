#include<iostream>
#include<queue>
using namespace std;
/*
N x M 지도가, 0은 바다, 1~10 높이를 가진 빙산
빙산은 주변의 접한 바다의 수만큰 녹게된다.
한덩이 빙산이 2덩이 이상으로 나누어지는 최소의 시간을 출력한다. 만약 2덩이 이상으로 안나누어 지고 다녹으면 0을 출력

빙산의 덩어리수를 구한다.(바다와 접한 면의 수 도 구하기.)
빙산의 위치의 주변의 바다 접한수만큼 줄인다.
2개 이상이면 최소시간 출력

*/
int N, M;
int map[302][302] = { 0 };
int visit[302][302] = { 0 };
int temp[302][302] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
typedef pair<int, int> pii;
void BFS(int x, int y) {
	visit[y][x] = 1;
	queue<pii> q;
	q.push(pii(y, x));
	while (!q.empty()){
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0)
					cnt++;
				if (map[ny][nx] != 0) {
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						q.push(pii(ny, nx));
					}
				}
			}
		}
		temp[cy][cx] = cnt;
	}
}
int div_ice() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				if (map[i][j] != 0) {
					cnt++;
					BFS(j, i);
				}
			}
		}
	}
	return cnt;
}
void melt_ice() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
			if (map[i][j] != 0) {
				if ((map[i][j] - temp[i][j]) <= 0)
					map[i][j] = 0;
				else
					map[i][j] -= temp[i][j];
				temp[i][j] = 0;
			}
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
	//빙산이 다녹을때 까지 반복
	int time = 0;
	while (true){
		// 빙산이 몇개 덩어린인지 확인
		int check = div_ice();
		
		if (check >= 2) {
			ans = time;
			break;
		}
		if (check == 0)
			break;
		//빙하 녹이기
		melt_ice();
		time++;
	}
	cout << ans << '\n';
	return 0;
}