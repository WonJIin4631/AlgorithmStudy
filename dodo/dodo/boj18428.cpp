#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
char map[7][7];
bool ans = false;
typedef pair<int, int> pii;
vector<pii> v;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check() {
	bool flag = false;
	for(int i = 0; i < v.size(); i++) {
		int x = v[i].second;
		int y = v[i].first;
		if (flag)
			break;
		for (int dir = 0; dir < 4; dir++) {
			if (flag)
				break;
			int nx = x;
			int ny = y;
			while (true) {
				nx += dx[dir];
				ny += dy[dir];
				if (nx < 0 || nx >= N||ny < 0 || ny >= N)
					break;
				if (map[ny][nx] == 'O')
					break;
				if (map[ny][nx] == 'T') {
					flag = true;
					break;
				}
			}
		}
	}
	return flag;
}
void DFS(int idx, int cnt) {
	if (cnt == 3) {
		if (ans)
			return;
		if (!check()) {
			ans = true;
		}
		return;
	}
	for (int i = idx; i < (N*N); i++) {
		int y = i /N;
		int x = i % N;	
		if (map[y][x] == 'X') {
			map[y][x] = 'O';
			DFS(i + 1, cnt + 1);
			map[y][x] = 'X';
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				v.push_back(pii(i, j));
			}
		}
	}
	DFS(0,0);
	if (ans)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}