#include<iostream>
#include<queue>
using namespace std;
/*
빨간, 파란 구슬을 상 하 좌 우로 기울여서 구멍에 빠지게 한다
동시에 두구슬이 빠지게 되면 안된다.
두 구슬은 동시에 같은 칸에 있을수 없다.
10번 이하로 움직여서 빼낼수 있으면 1 아니면 0

현재까지 움직인 횟수,파란구슬위치,빨간구슬위치 의 정보를 가지고 모든경우 탐색
동시에 같은칸에 있을경우-> 좌,우(y가 같을경우) 상,하(x가 같을경우)
좌 -> 왼쪽 구슬부터 이동
우 -> 오른쪽 구슬부터 이동
상 -> 위쪽 구슬 이동
하 -> 아래쪽 구슬이동

10번까지계산하지 않아도 이전까지 움직인 곳에 두 구슬이 다시 방문한경우는 찾지 않음-> 계속 똑같은 결과가 나올거같음
*/
int N, M;
char map[11][11];
int visit[11][11][11][11] = { 0 };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
struct info {
	int x;
	int y;
};
info blueB;
info redB;
bool ans = false;
bool check(info rb, info bb) {
	if (visit[bb.y][bb.x][rb.y][rb.x] ==1 ) {
		return false;
	}
	return true;
}
info moveB(info a, int dir) {
	int x = a.x;
	int y = a.y;
	while (true) {
		if (map[y + dy[dir]][x + dx[dir]] == 'O') {
			x += dx[dir];
			y += dy[dir];
			break;
		}
		if (map[y + dy[dir]][x + dx[dir]] != '.')
			break;
		x += dx[dir];
		y += dy[dir];
	}
	a.x = x, a.y = y;
	return a;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				redB.x = j, redB.y = i;
			}
			if (map[i][j] == 'B') {
				map[i][j] = '.';
				blueB.x = j, blueB.y = i;
			}
		}
	}

	visit[blueB.y][blueB.x][redB.y][redB.x] = 1;
	queue<pair<int, pair<info, info>>> q;
	q.push(make_pair(0, make_pair(blueB, redB)));
	int time = 0;
	while (true) {
		int qsz = q.size();
		if (time > 10)
			break;
		cout << "----------------------\n";
		for (int i = 0; i < qsz; i++) {
			info crB = q.front().second.second;
			info cbB = q.front().second.first;
			int cnt = q.front().first;
			q.pop();
			cout << ' ' << crB.y << ' ' << crB.x <<' '<< cbB.y<<' '<<cbB.x << '\n';
			if (map[crB.y][crB.x] == 'O') {
				if (map[cbB.y][cbB.x] != 'O') {
					ans = true;
					break;
				}
			}
			info nrB;
			info nbB;
			//상,하
			if (crB.x == cbB.x) {
				//빨간색 위에
				if (crB.y > cbB.y) {
					nrB = moveB(crB, 2);
					nbB = moveB(cbB, 2);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nbB.y += 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
					nbB = moveB(cbB, 3);
					nrB = moveB(crB, 3);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nrB.y -= 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}

				}
				//빨간색 아래
				else {
					nbB = moveB(cbB, 2);
					nrB = moveB(crB, 2);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nrB.y += 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
					nrB = moveB(crB, 3);
					nbB = moveB(cbB, 3);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nbB.y -= 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
				}
			}
			else {
				nrB = moveB(crB, 2);
				nbB = moveB(cbB, 2);

				if (map[nbB.y][nbB.x] != 'O') {
					if (check(nrB, nbB)) {
						visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
						q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
					}
				}
				nrB = moveB(crB, 3);
				nbB = moveB(cbB, 3);

				if (map[nbB.y][nbB.x] != 'O') {
					if (check(nrB, nbB)) {
						visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
						q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
					}
				}

			}
			//좌우
			if (crB.y == cbB.y) {
				//빨간색 왼쪽
				if (crB.x < cbB.x) {
					nrB = moveB(crB, 0);
					nbB = moveB(cbB, 0);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nbB.x += 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
					nbB = moveB(cbB, 1);
					nrB = moveB(crB, 1);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nrB.x -= 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
				}
				//빨간색이 오른쪽
				else {
					nrB = moveB(crB, 0);
					nbB = moveB(cbB, 0);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nrB.x += 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
					nbB = moveB(cbB, 1);
					nrB = moveB(crB, 1);
					if (map[nbB.y][nbB.x] != 'O') {
						if (nbB.y == nrB.y&&nbB.x == nrB.x)
							nbB.x -= 1;
						if (check(nrB, nbB)) {
							visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
							q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
						}
					}
				}
			}
			else {
				nrB = moveB(crB, 0);
				nbB = moveB(cbB, 0);

				if (map[nbB.y][nbB.x] != 'O') {
					if (check(nrB, nbB)) {
						visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
						q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
					}
				}
				nrB = moveB(crB, 1);
				nbB = moveB(cbB, 1);

				if (map[nbB.y][nbB.x] != 'O') {
					if (check(nrB, nbB)) {
						visit[nbB.y][nbB.x][nrB.y][nrB.x] = 1;
						q.push(make_pair(cnt + 1, make_pair(nbB, nrB)));
					}
				}
			}
		}
		if (ans)
			break;
		time++;
	}
	cout << ans << '\n';
	return 0;
}