#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
/*
도미노 타일은 2조각으로 나누어져있음
1~6사이 숫자가 적혀있음
타일은 N줄로 놓여져 있고, 홀수 중에는 N개, 짝수는 N-1타일이 놓여져있음
다른 타일로넘어갈려면 인접, 숫자가 같아야 됨
마지막줄 마지막 타일로 이동하는 가장 짧은 경로
만약 첫타일에서 이동할수 없는경우 첫줄의 가장 큰 번호를 가지고 있는 타일로 이동

N*2N 2차원 배열
홀수는 1부터,짝수는 2부터 시작
BFS 탐색하면서 이동했던 거리를 기록
타일의 순서대로 출력
*/
int map[502][502] = { 0 };
int visit[502][502] = { 0 };
int N;
int ans = 987654321;
vector<string> ans_s;
int dx[] = { 0,-1,1 };
int dy[] = { 1,0,0 };
// 입력
void input() {
	cin >> N;
	int x = 0;
	int y = 0;
	for (int i = 0; i < (N*N) - (N / 2); i++) {
		cin >> map[y][x] >> map[y][x + 1];
		x += 2;
		if (y % 2 == 0) {
			if (x == (2 * N)) {
				y++;
				x = 1;
			}
		}
		else if (y % 2 != 0) {
			if (x == (2 * N) - 1) {
				y++;
				x = 0;
			}
		}
	}
}
// 같은 타일에 있는지
bool c_tile(int x, int y, int nx, int ny) {
	if (ny == y) {
		if (y % 2 == 0) {
			if (abs(nx - x) == 1) {
				int l = min(nx, x);
				if (l % 2 == 0)
					return true;
			}
		}
		else {
			if (abs(nx - x) == 1) {
				int l = min(nx, x);
				if (l % 2 == 1)
					return true;
			}
		}
	}
	return false;
}

int c_tileNum(int x, int y) {
	int num = 0;
	if (y != 0) {
		for (int i = 0; i < y; i++) {
			if ((i % 2) == 0)
				num += N;
			else
				num += N - 1;
		}
		if (y % 2 == 0) {
			num += (x / 2) + 1;
		}
		else {
			num += ((x - 1) / 2) + 1;
		}
	}
	else {
		num = x / 2 + 1;
	}
	return num;
}
pair<int, int> get_tile(int x, int y) {
	if (y % 2 == 0) {
		if ((x % 2) == 1) {
			return{ x - 1,y };
		}
		else {
			return{ x + 1,y };
		}
	}
	else {
		if ((x % 2) == 1) {
			return{ x + 1,y };
		}
		else {
			return{ x - 1,y };

		}
	}
}
bool solve(int y, int x, string s) {
	queue < pair<pair<int, int>, pair<int, string>>> q;
	bool flag = false;
	visit[y][x] = 1;
	visit[y][x + 1] = 1;
	q.push(make_pair(make_pair(x, y), make_pair(1, s)));
	q.push(make_pair(make_pair(x + 1, y), make_pair(1, s)));
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second.first;
		string val = q.front().second.second;
		q.pop();
		int curTile = c_tileNum(cx, cy);
		ans_s[curTile] = val;
		if (cy == N - 1) {
			if (N % 2 == 1) {
				if ((cx == (2 * N) - 2) || (cx == (2 * N) - 1)) {
					ans = min(ans, cnt);
					flag = true;
					continue;
				}
			}
			else {
				if ((cx == (2 * N) - 3) || (cx == (2 * N) - 2)) {
					ans = min(ans, cnt);
					flag = true;
					continue;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < (2 * N) && ny >= 0 && ny < N) {
				if (map[ny][nx] != 0) {
					if (map[ny][nx] == map[cy][cx]) {
						if (visit[ny][nx] == 0) {
							visit[ny][nx] = c_tileNum(cx, cy);
							int can = c_tileNum(nx, ny);
							pair<int, int> nnval;
							nnval = get_tile(nx, ny);
							visit[nnval.second][nnval.first] = c_tileNum(cx, cy);
							q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, val + " " + to_string(can))));
							q.push(make_pair(nnval, make_pair(cnt + 1, val + " " + to_string(can))));

						}
					}
				}
			}
		}
	}
	if (!flag)
		return false;
	else
		return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	ans_s.resize((N*N) - (N / 2) + 1);

	if (solve(0, 0, "1")) {
		cout << ans << '\n';
		cout << ans_s[(N*N) - (N / 2)] << '\n';
	}
	else {
		int lastTile;
		bool flag = false;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 2 * N - 1; j >= 0; j--) {
				if (visit[i][j] != 0) {
					lastTile = c_tileNum(j, i);
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		int cnt = 1;
		for (int i = 0; i < ans_s[lastTile].length(); i++) {
			if (ans_s[lastTile][i] == ' ')
				cnt++;
		}
		cout << cnt << '\n';
		cout << ans_s[lastTile] << '\n';
	}
	return 0;
}