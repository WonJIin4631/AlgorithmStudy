#include<iostream>
#include<queue>
using namespace std;

int map[1002][1002];
bool visit[1002][1002][2] = { 0 };
int N, M;
int Hx, Hy;
int Ex, Ey;
struct Info{
	int x, y, wall;
};
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool isIn(int x, int y) {
	return x >= 1 && x <= M&&y >= 1 && y <= N;
}
int solve() {
	queue<Info> q;

	q.push({ Hx,Hy,0 });
	visit[Hy][Hx][0] = visit[Hy][Hx][1]= true;

	int time = 0;
	bool flag = false;
	while (!q.empty()){
		int qsz = q.size();
		while (qsz--){
			Info cur = q.front();
			q.pop();
			if (cur.x == Ex&&cur.y == Ey) {
				flag = true;
				break;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny)) {
					if (map[ny][nx] == 0) {
						if (visit[ny][nx][cur.wall] == false) {
							visit[ny][nx][cur.wall] = true;
							q.push({ nx,ny,cur.wall });
						}
					}
					else {
						if (cur.wall == 1)
							continue;
						if (visit[ny][nx][cur.wall+1] == false) {
							visit[ny][nx][cur.wall+1] = true;
							q.push({ nx,ny,cur.wall+1});
						}
					}
				}
			}
		}
		if (flag)
			break;
		time++;
	}
	if (!flag)
		time = -1;
	return time;
}
void init() {
	cin >> N >> M;
	cin >> Hy >> Hx;
	cin >> Ey >> Ex;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	init();
	cout << solve() << '\n';
	return 0;
}