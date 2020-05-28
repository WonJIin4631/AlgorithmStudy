#include <iostream>
using namespace std;
int n, m;
char map[40][40] = { 0, };
char map_ref[40][40] = { 0, };
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 1000000;

int res[100] = { 0, };
int m_cnt = 0;

void DFS(int x, int y, int dir, int move_num, int cnt) {
	if (m_cnt == move_num) {
		if (ans > cnt&& cnt != 0)
			ans = cnt;
		return;
	}
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == '.') {
		map[nx][ny] = '#';
		DFS(nx, ny, dir, move_num + 1, cnt);
		map[nx][ny] = '.';
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (dir == i)
				continue;
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == '.') {
				map[nx][ny] = '#';
				DFS(nx, ny, i, move_num + 1, cnt + 1);
				map[nx][ny] = '.';
			}
		}
	}
}

int main() {
	int ind = 0;
	while (cin >> n >> m) {
		ind++;
		ans = 1000000;
		char inp;
		m_cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
				map_ref[i][j] = map[i][j];
				if (map[i][j] == '.')m_cnt++;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] != '.') continue;

				for (int kk = 0; kk < 4; kk++) {
					map[i][j] = '#';
					DFS(i, j, kk, 1, 1);
					for (int y = 1; y <= n; y++) {
						for (int x = 1; x <= m; x++) {
							map[i][j] = map_ref[i][j];
						}
					}
				}
			}
		}
		if (ans == 1000000)ans = 0;
		if (ans == 0)ans = -1;
		if (m_cnt == 1)ans = 0;
		cout << "Case " << ind << ": " << ans << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = '\0';
				map_ref[i][j] = '\0 ';
			}
		}
	}
}
