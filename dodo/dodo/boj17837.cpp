#include<iostream>
#include<vector>
using namespace std;
/*
체스판 크기 N*N, 사용하는 말의 개수 K개
이동방향 상하좌우
턴 1번은 1~K번까지 순서대로 이동
한말이 이동할때 올려져 있는 말도 같이 이동
말이 4개 이상으로 쌓여지면 게임종료 턴이 1000번 이내 종료되면 턴의 수를 출력 1000초과이면 -1 출력

이동할려는 칸이 흰,빨간,파란 3가지로 구분
흰색 - 이동할려는 칸에 말이 있는 경우 위에 얹음
빨간색 - 쌓여 있는 순서가 바뀜 만약 말이 있는 경우 순서가 바뀐 상태로 얹힘
파란색 이동방향 반대로 하고 한칸 이동 ,만약 이동할 칸이 파란색이면 방향만 바꿈
체스판을 벗어나면 파란색과 같다.

처음 문제풀대는 말을 기준으로 했음 ->처리할게 많아서 복잡함

주어진 이동 조건에 맞게 이동한다.
말의 위치를 알수 있게 2차원 배열 선언
2차원 배열선언이유는 그자리에 있는 말이 어떤 순서대로 있는지 파악하기 위해
움직일 말이 몇번째 높이에 있는지 중요
움직일때 높이 ~ size()-1까지 다음 칸으로 이동 하고 빼준다
*/
struct info {
	int x;
	int y;
	int dir;
};

int dx[] = { 0, 1,-1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int N, K;
int ans = 1000;
int map[13][13] = { 0 };

vector<int> malMap[13][13];

info mal[11];
//입력
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		int x, y, dir;
		cin >> y >> x >> dir;
		mal[i] = { x,y,dir };
		malMap[y][x].push_back(i);
	}

}

int find_h(int y, int x, int idx) {
	for (int i = 0; i < malMap[y][x].size(); i++) {
		if (malMap[y][x][i] == idx) {
			return i;
		}
	}
}

int change_dir(int dir) {
	if (dir == 1) {
		return 2;
	}
	else if (dir == 2) {
		return 1;
	}
	else if (dir == 3) {
		return 4;
	}
	else if (dir == 4) {
		return 3;
	}
}

// 말이 한칸 이동
void moveMal(int idx) {
	int cx = mal[idx].x;
	int cy = mal[idx].y;
	int cd = mal[idx].dir;
	int nx = dx[cd] + cx;
	int ny = dy[cd] + cy;
	int h = find_h(cy, cx, idx);
	// 말이 체스판 벗어나지 않음
	if (nx >= 1 && nx <= N&&ny >= 1 && ny <= N) {
		//다음칸이 흰색
		if (map[ny][nx] == 0) {
			int cnt = 0;
			for (int i = h; i < malMap[cy][cx].size(); i++) {
				int temp = malMap[cy][cx][i];
				mal[temp].x = nx;
				mal[temp].y = ny;
				malMap[ny][nx].push_back(temp);
				cnt++;
			}
			for (int i = 0; i < cnt; i++) {
				malMap[cy][cx].pop_back();
			}
		}

		//다음칸이 빨간
		else if (map[ny][nx] == 1) {
			int cnt = 0;
			for (int i = malMap[cy][cx].size() - 1; i >= h; i--) {
				int temp = malMap[cy][cx][i];
				mal[temp].x = nx;
				mal[temp].y = ny;
				malMap[ny][nx].push_back(temp);
				cnt++;
			}
			for (int i = 0; i < cnt; i++) {
				malMap[cy][cx].pop_back();
			}

		}
		//다음칸 파랑
		else if (map[ny][nx] == 2) {
			int ncd = change_dir(cd);
			int nnx = cx + dx[ncd];
			int nny = cy + dy[ncd];
			mal[idx].dir = ncd;
			if (nnx >= 1 && nnx <= N&&nny >= 1 && nny <= N) {
				if (map[nny][nnx] != 2) {
					moveMal(idx);
				}
			}
		}
	}
	else {
		int ncd = change_dir(cd);
		int nnx = cx + dx[ncd];
		int nny = cy + dy[ncd];
		mal[idx].dir = ncd;
		if (nnx >= 1 && nnx <= N&&nny >= 1 && nny <= N) {
			if (map[nny][nnx] != 2) {
				moveMal(idx);
			}
		}
	}
}
bool check_fin() {
	for (int i = 1; i <= K; i++) {
		int x = mal[i].x;
		int y = mal[i].y;
		if (malMap[y][x].size() >= 4)
			return true;
	}
	return false;
}

void solve() {
	int turn = 0;
	bool flag = false;
	while (true) {
		if (turn > 1000)
			break;
		for (int i = 1; i <= K; i++) {
			moveMal(i);
			if (check_fin()) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		turn++;
	}
	if (!flag)
		ans = -1;
	else {
		ans = turn + 1;
	}
}

int main() {
	input();
	solve();
	cout << ans << '\n';
	return 0;
}