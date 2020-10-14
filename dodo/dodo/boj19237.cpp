#include<iostream>

using namespace std;

struct shark_Info{
	int x;
	int y;
	int d;
};
struct smell_Info {
	int x;
	int y;
	int time;
};

int N, M, K;
int smellMap[21][21] = { 0 };
int smellTimeMap[21][21] = { 0 };
int sharkMap[21][21] = { 0 };
int sharkDir[402][21][21] = { 0 };
bool check_shark[402] = { 0 };

shark_Info shark[402];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int ans = -1;
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
void init() {
	cin >> N >> M >> K;
	//상어 좌표
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n != 0) {
				smellMap[i][j] = n;
				smellTimeMap[i][j] = K;
				shark[n] = { j,i,0 };
			}
		}
	}
	//상어 방향성
	for (int i = 1; i <= M; i++) {
		cin >> shark[i].d;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> sharkDir[i][j][k];
			}
		}
	}
}
bool shark_move(int time) {
	for (int idx = M; idx >= 1; idx--) {
		if (check_shark[idx] == false) {
			int curDir = shark[idx].d;
			bool flag = false;
			//냄새 없는지 확인
			for (int d = 1; d <= 4; d++) {
				int nx = shark[idx].x + dx[sharkDir[idx][curDir][d]];
				int ny = shark[idx].y + dy[sharkDir[idx][curDir][d]];
				//경계값 확인
				if (isIn(nx, ny)) {
					if (smellMap[ny][nx] == 0) {
						// 만약 상어가 있다면 밀어내기
						if (sharkMap[ny][nx] != 0)
							check_shark[sharkMap[ny][nx]] = true;
						sharkMap[ny][nx] = idx;
						shark[idx].d = sharkDir[idx][curDir][d];
						flag = true;
					}
				}
				if (flag)
					break;
			}
			//냄새 없는곳이 없으면 자신의 냄새 쪽확인
			if (flag == false) {
				for (int d = 1; d <= 4; d++) {
					int nx = shark[idx].x + dx[sharkDir[idx][curDir][d]];
					int ny = shark[idx].y + dy[sharkDir[idx][curDir][d]];
					//경계값 확인
					if (isIn(nx, ny)) {
						if (smellMap[ny][nx] == idx) {
							if (sharkMap[ny][nx] != 0)
								check_shark[sharkMap[ny][nx]] = true;
							sharkMap[ny][nx] = idx;
							shark[idx].d = sharkDir[idx][curDir][d];
							flag = true;
						}
					}
					if (flag)
						break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (smellTimeMap[i][j] == 0)
				continue;
			smellTimeMap[i][j]--;
			if (smellTimeMap[i][j] == 0)
				smellMap[i][j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sharkMap[i][j] != 0) {
				int sIdx = sharkMap[i][j];
				smellMap[i][j] = sIdx;
				smellTimeMap[i][j] = K;
				shark[sIdx].x = j; shark[sIdx].y = i;
				cnt++;
			}
			sharkMap[i][j] = 0;
		}
	}
	if (cnt == 1)
		return true;
	return false;
}
void solve() {
	for (int time = 1; time <= 1000; time++) {
		if (shark_move(time)) {
			ans = time;
			break;
		}
	}
	cout << ans << '\n';
}
int main() {
	init();
	solve();
	return 0;
}