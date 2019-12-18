#include<iostream>
#include<queue>
using namespace std;

char map[11][11];
//10번 이하로 움직여야됨 빨간구슬만 구멍에 빠지기
int visit[2][11][11];
int N, M;
struct block
{
	int rbx;
	int rby;
	int bbx;
	int bby;
	block(int rbx, int rby, int bbx, int bby) : rbx(rbx), rby(rby), bbx(bbx), bby(bby) {}
};


queue<pair<int,block>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void solve() {
	while (!q.empty()) {
		int cnt = q.front().first;
		block pos = q.front().second;
		int rx = pos.rbx;
		int ry = pos.rby;
		int bx = pos.bbx;
		int by = pos.bby;
		q.pop();

	}
}
int main() {
	cin >> N >> M;
	int rb[2];
	int bb[2];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rb[0] = i;
				rb[1] = j;
			}
			else if (map[i][j] == 'B') {
				bb[0] = i;
				bb[1] = j;
			}
		}
	}
	visit[0][rb[0]][rb[1]] = 1;
	visit[1][bb[0]][bb[1]] = 1;
	q.push(make_pair(0, block(rb[0],rb[1],bb[0],bb[1])));
}