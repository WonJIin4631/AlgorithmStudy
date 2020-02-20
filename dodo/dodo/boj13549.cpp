#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
/*
빨간, 파란 구슬을 상 하 좌 우로 기울여서 구멍에 빠지게 한다
동시에 두구슬이 빠지게 되면 안된다.
두 구슬은 동시에 같은 칸에 있을수 없다.
10번 이하로 움직여서 빼낼수 있으면 1 아니면 0

현재까지 움직인 횟수,파란구슬위치,빨간구슬위치 의 정보를 가지고 모든경우 탐색
동시에 같은칸에 있을경우-> 원래 있던위치와 이동한 위치의 거리 차를 비교하여 값이 높게온것이 반대방향으로 이동
10번까지계산하지 않아도 이전까지 움직인 곳에 두 구슬이 다시 방문한경우는 찾지 않음-> 계속 똑같은 결과가 나올거같음
*/
int N, M;
char map[11][11];
bool visit[11][11][11][11] = { false };
int rbx, rby, bbx, bby;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
struct info {
	int rbx, rby, bbx, bby;
};
bool ans = false;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				rbx = j, rby = i;
			}
			if (map[i][j] == 'B') {
				map[i][j] = '.';
				bbx = j, bby = i;
			}
		}
	}
	visit[rby][rbx][bby][bbx] = true;
	queue<info> q;
	q.push({ rbx,rby,bbx,bby });
	int time = 0;
	while (true) {
		//9번째 이동까지 확인해야됨 10번째 이동한 위치가 구멍이여야해서
		if (time >= 10)
			break;
		int qsz = q.size();
		bool flag = false;
		for (int i = 0; i < qsz; i++) {
			int crbx, crby, cbbx, cbby;
			crbx = q.front().rbx, crby = q.front().rby, cbbx = q.front().bbx, cbby = q.front().bby;
			q.pop();
			//4방향
			for (int k = 0; k < 4; k++) {
				int nrbx=crbx, nrby=crby, nbbx=cbbx, nbby=cbby;
				while (true){
					if (map[nrby + dy[k]][nrbx+dx[k]] == '#'||map[nrby][nrbx]=='O')
						break;
					nrbx += dx[k];
					nrby += dy[k];
				}
				while (true) {
					if (map[nbby + dy[k]][nbbx + dx[k]] == '#' || map[nbby][nbbx] == 'O')
						break;
					nbbx += dx[k];
					nbby += dy[k];
				}

				if (map[nbby][nbbx] != 'O'&&map[nrby][nrbx] == 'O') {
					flag = true;
					break;
				}
				if (nrbx == nbbx && nrby == nbby) {
					if (map[nbby][nbbx] == 'O')
						continue;
					//이동한 위치와 원래 위치의 거리차를 구해 더멀리 이동한게 다른칸으로 한칸 이동
					if (abs(crbx - nrbx) + abs(crby - nrby) > abs(cbbx - nbbx) + abs(cbby - nbby)) {
						nrbx -= dx[k];
						nrby -= dy[k];
					}
					else {
						nbbx -= dx[k];
						nbby -= dy[k];
					}
				}
				if (!visit[nrby][nrbx][nbby][nbbx]) {
					visit[nrby][nrbx][nbby][nbbx] = true;
					q.push({ nrbx,nrby,nbbx,nbby });
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			ans = true;
			break;
		}
		time++;
	}
	cout << ans << '\n';
	return 0;
}