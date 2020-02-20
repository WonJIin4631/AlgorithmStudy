#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
/*
����, �Ķ� ������ �� �� �� ��� ��￩�� ���ۿ� ������ �Ѵ�
���ÿ� �α����� ������ �Ǹ� �ȵȴ�.
�� ������ ���ÿ� ���� ĭ�� ������ ����.
10�� ���Ϸ� �������� ������ ������ 1 �ƴϸ� 0

������� ������ Ƚ��,�Ķ�������ġ,����������ġ �� ������ ������ ����� Ž��
���ÿ� ����ĭ�� �������-> ���� �ִ���ġ�� �̵��� ��ġ�� �Ÿ� ���� ���Ͽ� ���� ���Կ°��� �ݴ�������� �̵�
10������������� �ʾƵ� �������� ������ ���� �� ������ �ٽ� �湮�Ѱ��� ã�� ����-> ��� �Ȱ��� ����� ���ðŰ���
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
		//9��° �̵����� Ȯ���ؾߵ� 10��° �̵��� ��ġ�� �����̿����ؼ�
		if (time >= 10)
			break;
		int qsz = q.size();
		bool flag = false;
		for (int i = 0; i < qsz; i++) {
			int crbx, crby, cbbx, cbby;
			crbx = q.front().rbx, crby = q.front().rby, cbbx = q.front().bbx, cbby = q.front().bby;
			q.pop();
			//4����
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
					//�̵��� ��ġ�� ���� ��ġ�� �Ÿ����� ���� ���ָ� �̵��Ѱ� �ٸ�ĭ���� ��ĭ �̵�
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