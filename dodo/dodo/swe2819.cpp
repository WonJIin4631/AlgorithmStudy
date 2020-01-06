#include<iostream>
#include<set>
#include<string>
#include<string.h>
using namespace std;

int num_cnt[10];
char num[10];
char map[5][5];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
set<string> Set;
int ans = 0;
void DFS(int x, int y, string s, int cnt) {
	if (cnt == 7) {
		if (Set.find(s) == Set.end()) {
			ans++;
			Set.insert(s);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
			s += map[ny][nx];
			DFS(nx, ny, s, cnt + 1);
			s.pop_back();
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < 10; i++) {
		num[i] = i + '0';
	}
	for (int t = 1; t <= T; t++) {
		memset(num_cnt, 0, sizeof(num_cnt));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		string s = "";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				s += map[i][j];
				DFS(j, i, s, 1);
				s.pop_back();
			}
		}
		cout << '#' << t << ' ' << ans << '\n';
		ans = 0;
		Set.clear();
	}

	return 0;
}