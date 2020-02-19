#include<iostream>
#include<queue>
using namespace std;
/*
����, �Ķ� ������ �� �� �� ��� ��￩�� ���ۿ� ������ �Ѵ�
���ÿ� �α����� ������ �Ǹ� �ȵȴ�.
�� ������ ���ÿ� ���� ĭ�� ������ ����.
10�� ���Ϸ� �������� ������ ������ 1 �ƴϸ� 0

������� ������ Ƚ��,�Ķ�������ġ,����������ġ �� ������ ������ ����� Ž��
���ÿ� ����ĭ�� �������-> ��,��(y�� �������) ��,��(x�� �������)
�� -> ���� �������� �̵�
�� -> ������ �������� �̵�
�� -> ���� ���� �̵�
�� -> �Ʒ��� �����̵�

10������������� �ʾƵ� �������� ������ ���� �� ������ �ٽ� �湮�Ѱ��� ã�� ����-> ��� �Ȱ��� ����� ���ðŰ���
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
			//��,��
			if (crB.x == cbB.x) {
				//������ ����
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
				//������ �Ʒ�
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
			//�¿�
			if (crB.y == cbB.y) {
				//������ ����
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
				//�������� ������
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