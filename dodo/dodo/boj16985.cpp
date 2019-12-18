#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int map[6][5][6][6];//순서,종류,세로,가로
			
int ans = 987654321;
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
vector<int> dir_list;
int idx_list[] = { 0,1,2,3,4 };
struct node {
	int x;
	int y;
	int z;
	int cnt;
	node(int x, int y, int z, int cnt) : x(x), y(y), z(z), cnt(cnt) {}
};

void change() {
	for (int t = 0; t < 5; t++) {
		for (int k = 1; k <= 3; k++) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					map[t][k][j][4 - i] = map[t][k-1][i][j];
				}
			}
		}
	}
}
void solve() {
	bool visit[6][6][6] = { false };
	queue<node> q;
	if (map[idx_list[0]][dir_list[0]][0][0] == 1) {
		visit[0][0][0] = 1;
		node p = { 0,0,0,0 };
		q.push(p);
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int cnt = q.front().cnt;
		q.pop();
		if (z == 4 && x == 4 && y == 4) {
			if (ans > cnt)
				ans = cnt;
			continue;
		}
		if (ans <= cnt)
			continue;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5) {
				if (map[idx_list[nz]][dir_list[nz]][ny][nx] == 1 && visit[nz][ny][nx] == 0) {
					visit[nz][ny][nx] = 1;
					q.push({ nx,ny,nz,cnt + 1 });
				}
			}
		}
	}
}

void dfs(int idx) {
	if (idx == 5) {
		solve();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir_list.push_back(i);
		dfs(idx + 1);
		dir_list.pop_back();
	}
}
void per() {
	do {
		dfs(0);
		if (ans == 12)
			return;
	} while (next_permutation(idx_list,idx_list+5));
}
int main() {

	for (int i = 0; i < 5; i++) {	
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[i][0][j][k];
			}
		}
	}

	change();
	per();
	if (ans != 987654321) {
		cout << ans << '\n';
	}
	else
		cout << -1 << '\n';
	return 0;
}