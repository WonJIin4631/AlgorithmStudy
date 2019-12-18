#include<iostream>
#include<queue>
using namespace std;

int N, M;
int map[1001][1001];
int tomato_cnt=0;
int ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;
void BFS() {
	int cnt = 0;
	int time = 0;
	int qsize;
	while (!q.empty()){
		qsize = q.size();
		for (int j = 0; j < qsize; j++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
					if (map[ny][nx] == 0) {
						map[ny][nx] = 1;
						cnt++;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
		if (q.size() != 0)
			time++;
	}
	if (cnt == tomato_cnt)
		ans = time;
	else
		ans = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				tomato_cnt++;
			else if (map[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	if (tomato_cnt == 0) {
		ans = 0;
	}
	else {
		BFS();
	}
	cout << ans << '\n';
}