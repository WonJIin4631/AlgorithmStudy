#include<iostream>
#include<algorithm>
using namespace std;
/*
���ƴ� ������ 3�� ������ �ִ�. ���� �ϳ��� ���ױ� ���Ѵ�. 1��� ���� �ǰԵǸ� �����¿�� ���� ���´�.
�ٸ� ���ٰ� ��ԵǸ� ���� �״´�. �� ��ĭ�� ������ �����Ѵ�. ���ƴ� �ּ����� ������� 3���� ���� ������ ���Ѵ�.
DFS
*/

int map[11][11];
int visit[11][11];
int N;
int dx[] = {0, -1,1,0,0 };
int dy[] = {0, 0,0,-1,1 };
int ans = 987654321;
void DFS(int X,int Y,int sum,int cnt) {
	if (cnt == 3) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++) {
			if (visit[i][j] == 0) {
				bool flag = true;
				int cost = 0;
				for (int k = 0; k < 5; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (visit[ny][nx] != 0) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int k = 0; k < 5; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						cost += map[ny][nx];
						visit[ny][nx] = cnt+1;
					}
					DFS(j,i, sum + cost, cnt + 1);
					for (int k = 0; k < 5; k++) {
						int ny = i + dy[k];
						int nx = j + dx[k];
						visit[ny][nx] = 0;
					}
				}
			}
		}
	}
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	DFS(1, 1, 0, 0);
	cout << ans << '\n';

	return 0;
}