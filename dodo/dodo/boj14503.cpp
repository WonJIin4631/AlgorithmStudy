#include<iostream>
using namespace std;
/*
ũ�� N*M ���� 0:�� 1:�� 2:�� 3:��
û�ұⰡ û���ϴ� ĭ�� ����
��ĭ�� 0 ���� 1
������ġ û��
���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
�־��� ���ǿ� �°� �̵� -�ùķ��̼�
��->��->��->��
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