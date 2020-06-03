#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std;

struct info {
	int x;
	int y;
};
char map[106][106];
bool key[27];
int ans = 0;
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<info> q;
queue<info> door[27];
void init() {
	ans = 0;
	q = queue<info>();
	for (int i = 0; i <= 26; i++) {
		door[i] = queue<info>();
		key[i] = false;
	}
	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = map[i][M + 1] = '.';
	}
	for (int i = 0; i <= M + 1; i++) {
		map[0][i]=map[N+1][i] = '.';
	}
}
void start(int y,int x) {
	map[y][x] = '*';
	q.push({ x,y });
	while (!q.empty()){
		info cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx >= 0 && nx <= M + 1 && ny >= 0 && ny <= N + 1) {
				if (map[ny][nx] == '*')
					continue;
				else if (map[ny][nx] == '$') {
					ans++;
				}
				else if (map[ny][nx] >= 'a'&&map[ny][nx] <= 'z') {
					int temp = map[ny][nx] - 'a';
					if (key[temp] == false) {
						key[temp] = true;
						while (!door[temp].empty()){
							q.push(door[temp].front());
							door[temp].pop();
						}
					}
				}
				else if (map[ny][nx] >= 'A'&&map[ny][nx] <= 'Z') {
					int temp = map[ny][nx] - 'A';
					if (key[temp] == false) {
						map[ny][nx] = '*';
						door[temp].push({ nx,ny });
						continue;
					}
				}
				map[ny][nx] = '*';
				q.push({ nx,ny });
			}
		}
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		init();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
			}
		}
		string s;
		cin >> s;
		if (s != "0") {
			for (int i = 0; i < s.length(); i++) {
				key[s[i] - 'a'] = true;
			}
		}
		start(0, 0);
		cout << ans << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}