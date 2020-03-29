#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
/*
NxM 격자판 궁수 3명 배치, 한칸에는 최대 1명의 궁수만 존재, 궁수는 한 턴에 적하나 공격가능, 궁수는 동시에 공격,
공격거리는 D이하 가까운 적 , 여럿이 잇으면 가장 왼쪽, 같은적이 여러 궁수한테 공격 당할수 있다.
공격 받은 적은 제외, 한턴이 끝나면 적은 한칸 아래로 이동, 모든 적이 격자판에서 제외되면 게임끝

M개의 칸에 3명의 궁수를 놔둘수 있는 경우를 구한다-> prev퍼뮤로 모든 경우를 탐색
주어진 조건에 맞게 시뮬
적이 움직이는 것보다 궁수의 위치를 한칸씩 위로 이동한다.
같은 거리일때 왼쪽에서 부터 탐색(좌상우) 이순서대로 탐색?

잡은 적의 수를 비교해서 답을 저장

*/

struct info {
	int y;
	int x;
	info(int y, int x) :y(y), x(x) {};
};
int N, M, D;
int ans = 0;
int gupos[16] = { 0 };
vector<info> archor;
vector<vector<int>> map;

void solve() {
	vector<vector<int>> tmp_map = map;
	vector<info> tmp_archor = archor;
	vector<vector<int>> visit(N + 1, vector<int>(M, 0));

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		queue<pair<int, int>> q;
		for (int j = 0; j < 3; j++) {
			bool check = false;
			for (int distance = 1; distance <= D; distance++) {
				int dy = -1;
				int dx = (distance - 1)*(-1);
				for (int k = 1; k < 2 * distance; k++) {
					int ny = tmp_archor[j].y + dy;
					int nx = tmp_archor[j].x + dx;
					dy = (k >= distance) ? dy + 1 : dy - 1;
					dx += 1;
					if (ny < 0 || nx < 0 || nx >= M)
						continue;
					if (tmp_map[ny][nx] == 1) {
						if (visit[ny][nx] == 0) {
							cnt++;
							visit[ny][nx] = 1;
							q.push(make_pair(ny, nx));
						}
						check = true;
						break;
					}
				}
				if (check)
					break;
			}
			tmp_archor[j].y--;
		}
		while (!q.empty()) {
			int ny = q.front().first;
			int nx = q.front().second;
			q.pop();
			tmp_map[ny][nx] = 0;
		}
	}
	ans = max(ans, cnt);
}

void per() {
	do{
		for (int i = 0; i < M; i++) {
			if (gupos[i] == 1) {
				archor.push_back(info(N, i));
			}
		}
		solve();
		archor.clear();
	} while (prev_permutation(gupos,gupos+M));
}
int main() {
	cin >> N >> M >> D;
	map = vector<vector<int>>(N + 1, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		gupos[i] = 1;
	}
	per();
	cout << ans << '\n';
	return 0;
}