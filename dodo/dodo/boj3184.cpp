#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
��Ÿ���� #, ���� o, ����� v ���翡�� Ż���� ���� ����
���� ���� ���� �� ���� ������ ���븦 �̱� 
�ݴ�� ������ ���� ����

�湮���� ���� ĭ �������� BFS Ž��
�������� ���翡�� ������� ���Ǽ��� ���Ͽ� ���� ����, ���Ǽ��� ����
*/
char map[252][252];
int visit[252][252];
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans_sheep = 0;
int ans_wolf = 0;
void BFS(int x,int y) {
	int wolf = 0;
	int sheep = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;
	while (!q.empty()){
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		if (map[cy][cx] == 'v') {
			wolf++;
		}
		else if (map[cy][cx] == 'o') {
			sheep++;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] != '#') {
						visit[ny][nx] = 1;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
	if (wolf < sheep)
		ans_wolf -= wolf;
	else
		ans_sheep -= sheep;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'v')
				ans_wolf++;
			else if (map[i][j] == 'o')
				ans_sheep++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]==0) {
				BFS(j, i);
			}
		}
	}
	cout << ans_sheep << ' ' << ans_wolf << '\n';
	return 0;
}