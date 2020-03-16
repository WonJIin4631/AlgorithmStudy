#include<iostream>
#include<queue>
using namespace std;
/*
N x M ������, 0�� �ٴ�, 1~10 ���̸� ���� ����
������ �ֺ��� ���� �ٴ��� ����ū ��Եȴ�.
�ѵ��� ������ 2���� �̻����� ���������� �ּ��� �ð��� ����Ѵ�. ���� 2���� �̻����� �ȳ����� ���� �ٳ����� 0�� ���

������ ������� ���Ѵ�.(�ٴٿ� ���� ���� �� �� ���ϱ�.)
������ ��ġ�� �ֺ��� �ٴ� ���Ѽ���ŭ ���δ�.
2�� �̻��̸� �ּҽð� ���

*/
int N, M;
int map[302][302] = { 0 };
int visit[302][302] = { 0 };
int temp[302][302] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
typedef pair<int, int> pii;
void BFS(int x, int y) {
	visit[y][x] = 1;
	queue<pii> q;
	q.push(pii(y, x));
	while (!q.empty()){
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
				if (map[ny][nx] == 0)
					cnt++;
				if (map[ny][nx] != 0) {
					if (visit[ny][nx] == 0) {
						visit[ny][nx] = 1;
						q.push(pii(ny, nx));
					}
				}
			}
		}
		temp[cy][cx] = cnt;
	}
}
int div_ice() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				if (map[i][j] != 0) {
					cnt++;
					BFS(j, i);
				}
			}
		}
	}
	return cnt;
}
void melt_ice() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
			if (map[i][j] != 0) {
				if ((map[i][j] - temp[i][j]) <= 0)
					map[i][j] = 0;
				else
					map[i][j] -= temp[i][j];
				temp[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//������ �ٳ����� ���� �ݺ�
	int time = 0;
	while (true){
		// ������ � ������� Ȯ��
		int check = div_ice();
		
		if (check >= 2) {
			ans = time;
			break;
		}
		if (check == 0)
			break;
		//���� ���̱�
		melt_ice();
		time++;
	}
	cout << ans << '\n';
	return 0;
}