#include<iostream>
#include<queue>
using namespace std;

int dir_x[8] = { 1, 2, 1, 2, -1, -2, -1, -2 };
int dir_y[8] = {2,1,-2,-1 ,-2,-1 ,2,1 };

void BFS(int a,int b, int c,int d,int e) {
		queue<pair<int,int>> q;
		int visit[300 + 1][300 + 1] = { 0, };
		int check[300 + 1][300 + 1] = { 0 ,};
		int mapSize = a;
		int ans = 999999999;
		int e_x = d;
		int e_y = e;
		q.push(make_pair(b,c));
		visit[b][c] = 1;
		while (!q.empty()) {
			int s_x = q.front().first;
			int s_y = q.front().second;
			q.pop();
			if ((s_x == e_x) && (s_y == e_y)) {
				ans = check[s_x][s_y];
			}
			for (int j = 0; j < 8; j++) {
				int n_x, n_y;
				n_x = s_x + dir_x[j];
				n_y = s_y + dir_y[j];
				if (n_x >= 0 && n_x < mapSize && n_y >= 0 && n_y < mapSize) {
					if (visit[n_x][n_y] != 1) {
						visit[n_x][n_y] = 1;
						q.push(make_pair(n_x, n_y));
						check[n_x][n_y] = check[s_x][s_y]+1;
					}
				}
			}
		}
		cout << ans << endl;
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int size,start_x, start_y, end_x, end_y;
		cin >> size;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		BFS(size, start_x, start_y, end_x, end_y);
	}
}