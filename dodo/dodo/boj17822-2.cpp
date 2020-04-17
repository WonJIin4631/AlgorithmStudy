#include<iostream>
#include<deque>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M, T;
struct info{
	int x;
	int d;
	int k;
};
deque<int> pan[52];
bool visit[52][52] = { 0 };
typedef pair<int, int> pii;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void check_same() {
	memset(visit, false, sizeof(visit));
	queue<pii> q;
	int sumNum = 0;
	int cntNum = 0;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (pan[i][j] != 0) {
				if (visit[i][j] == 0) {
					//현재 값이랑 같은지 비교할 변수
					int curNum = pan[i][j];
					visit[i][j] = 1;
					q.push(pii(i, j));
					int samecnt = 0;
					while (!q.empty()) {
						int x = q.front().second;
						int y = q.front().first;
						cntNum++;
						sumNum += pan[y][x];
						if (samecnt > 0) {
							pan[y][x] = 0;
						}
						q.pop();
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0)
								nx = M - 1;
							else if (nx >= M)
								nx = 0;
							if (ny >= 1 && ny <= N) {
								if (visit[ny][nx] == 0&&pan[ny][nx]!=0) {
									if (pan[ny][nx] == curNum) {
										samecnt++;
										visit[ny][nx] = 1;
										q.push(pii(ny, nx));
									}
								}
							}
						}
					}
					if (samecnt > 0) {
						flag = true;
						pan[i][j] = 0;
					}
				}
			}
		}
	}
	if (!flag) {
		double avgNum = (double)sumNum / (double)cntNum;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (pan[i][j] != 0) {
					if (pan[i][j] > avgNum)
						pan[i][j] -= 1;
					else if (pan[i][j] < avgNum)
						pan[i][j] += 1;
				}
			}
		}
	}
}
void move_pan(int idx,int dir,int cnt) {
	cnt %= M;
	if (dir == 0) {
		for (int i = 0; i < cnt; i++) {
			int temp = pan[idx].back();
			pan[idx].push_front(temp);
			pan[idx].pop_back();
		}
	}
	else {
		for (int i = 0; i < cnt; i++) {
			int temp = pan[idx].front();
			pan[idx].push_back(temp);
			pan[idx].pop_front();
		}
	}
}
int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			pan[i].push_back(n);
		}
	}
	for (int i = 0; i < T; i++) {
		int idx, dir, cnt;
		cin >> idx >> dir >> cnt;
		for (int j = 1; j <= N; j++) {
			if (j%idx == 0) {
				move_pan(j, dir, cnt);
			}
		}
		check_same();
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			ans += pan[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}