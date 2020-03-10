#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
/*
ġ�� ���ڿ��� �ܺο� ������ ĭ�� 2���̻��̸� ��´�.
1�ð� �������� ��°� ����ȴ�.
ġ��ο� �� ���� ������ �װ��� �ܺ� ���Ⱑ�ƴϴ�.


2���� �迭 ġ���� ����, �ܺΰ������� �Ǻ��� ��, ����Ƚ�� ��, �湮�ߴ��� Ȯ�� ��
�־��� ��,�� ���� �ܿ��� �ܺΰ����̴�.
�ܺΰ��⸦ BFS�� Ž���ϸ� �����¿쿡 ����Ƚ���� ���Ѵ�.
ġ���� ���¿��� �ܺΰ��Ⱑ �ƴϸ�,ġ���� �κ��ϴ� ġ��κ��� ����Ƚ���� 2�̻��̸� ���δ�.
*/
int map[106][106] = { 0 };
bool visit[106][106] = { 0 };
int cMap[104][104] = { 0 };
int N, M;
typedef pair<int, int> pii;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;
int check_air() {
	int cnt = 0;
	queue <pii> q;
	q.push(pii(0, 0));
	visit[0][0] = true;
	while (!q.empty()){
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= M+ 1 && ny >= 0 && ny <= N + 1) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] == 0) {
						visit[ny][nx] = true;
						q.push(pii(ny, nx));
						//4���� ��������
						for (int k = 0; k < 4; k++) {
							int nnx = nx + dx[k];
							int nny = ny + dy[k];
							if (nnx >= 0 && nnx <= M + 1 && nny >= 0 && nny <= N + 1) {
								if(map[nny][nnx]==1)
									cMap[nny][nnx]++;
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}
void melt() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			//ġ�������϶�
			if (map[i][j] == 1) {
				//����Ƚ�� 2���̻��϶�
				if (cMap[i][j] >= 2) {
					map[i][j] = 0;
				}
			}
		}
	}
}
void solve() {
	int time = 0;
	while (true){
		int cnt = check_air();
		if (cnt == (N + 2)*(M + 2)) {
			ans = time;
			break;
		}
		melt();
		memset(visit, false, sizeof(visit));
		memset(cMap, 0, sizeof(cMap));
		time++;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}