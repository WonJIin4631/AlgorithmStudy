#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<string>
using namespace std;

/*
바이러스 M개 넣고 동시에 퍼짐, 크기는 NxN
빈칸은 0  벽은 1 바이러스 가능 위치 2
빈칸의 개수 + 바이러스가 가능하지만 선택되지 않은 칸의 개수 만큼 복제 되면 모든칸에 복제된것이다. -> 모든칸을 계속 확인하는 것을 줄이기 위해서

조합+ 시뮬?

*/

typedef pair<int, int> pii;
int map[51][51];
int visit[51][51];
int leftCan = 0;
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 987654321;
bool checkVirus[11] = { false };
vector<pii> virus;

void move_virus() {
	queue<pii> q;
	// 선택된 바이러스
	for (int i = 0; i < virus.size(); i++) {
		if (checkVirus[i]) {
			q.push(pii(virus[i].first, virus[i].second));
			visit[virus[i].first][virus[i].second] = 1;
		}
	}
	int day = 0;
	//현재까지 퍼진 칸의 개수를 확인 변수
	int cnt = 0;
	while (true) {

		//현재 큐의 크기가 하루동안 복제 있는 바이러스
		int qSZ = q.size();
		if (qSZ == 0)
			break;
		//복제 안됫을 경우 확인
		bool flag = false;
		for (int i = 0; i < qSZ; i++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					//벽이 아니거나 방문하지 않은 칸으로 퍼짐
					if (visit[ny][nx] == 0) {
						if (map[ny][nx] != 1) {
							visit[ny][nx] = 1;
							q.push(pii(ny, nx));
							//복제된 칸으 개수 증가
							cnt++;
							flag = true;
						}
					}
				}
			}
		}
		if (flag)
			day++;
		//지금까지 복제된 칸의 개수와 복제될 칸의 개수 비교
		if (cnt == (leftCan + virus.size() - M)) {
			ans = min(ans, day);
			break;
		}
	}
	memset(visit, 0, sizeof(visit));
}
// 바이러스 가능한 칸의 위치중 M개를 선택
void choose_virus(int cnt, int idx) {
	if (cnt == M) {
		move_virus();
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (!checkVirus[i]) {
			checkVirus[i] = true;
			choose_virus(cnt + 1, i + 1);
			checkVirus[i] = false;
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				leftCan++;
			}
			if (map[i][j] == 2) {
				virus.push_back(pii(i, j));
			}
		}
	}
	choose_virus(0, 0);
	if (ans == 987654321)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}