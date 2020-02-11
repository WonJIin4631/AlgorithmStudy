#include<iostream>
using namespace std;
/*
크기 N*M 방향 0:북 1:동 2:남 3:서
청소기가 청소하는 칸의 개수
빈칸은 0 벽은 1
현재위치 청소
왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
주어진 조건에 맞게 이동 -시뮬레이션
북->동->남->서
*/
struct info {
	int x;
	int y;
	int dir;
};
int N, M;
int map[51][51];
int visit[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
info robot;

void input() {
	cin >> N >> M;
	cin >> robot.y >> robot.x >> robot.dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}
int check_L(int d) {
	int nd = d - 1;
	if (nd ==-1 )
		nd = 3;
	return nd;
}
int go_back(int d) {
	if (d == 0)
		return 2;
	else if (d == 1)
		return 3;
	else if (d == 2)
		return 0;
	else
		return 1;
}
int solve() {
	bool flag = false;
	int cnt = 0;
	while (true){
		if (flag)
			break;
		if (visit[robot.y][robot.x] == 0) {
			cnt++;
		}
		visit[robot.y][robot.x] = 1;
		bool c_turn = true;
		for (int i = 0; i < 4; i++) {
			robot.dir = check_L(robot.dir);
			int nx = robot.x + dx[robot.dir];
			int ny = robot.y + dy[robot.dir];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0) {
					if (visit[ny][nx] == 0) {
						robot.x = nx;
						robot.y = ny;
						c_turn = false;
						break;
					}
				}
			}
		}
		if (c_turn) {
			bool c_back = true;
			int nx = robot.x + dx[go_back(robot.dir)];
			int ny = robot.y + dy[go_back(robot.dir)];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0) {
					robot.x = nx;
					robot.y = ny;
					c_back = false;
				}
			}
			if (c_back) {
				flag = true;
			}
		}
	}
	return cnt;
}
int main() {
	input();
	cout << solve() << '\n';
	return 0;
}