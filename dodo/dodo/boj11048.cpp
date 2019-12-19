#include<iostream>
using namespace std;

int N, M;
int map[1001][1001];
int dx[] = { -1,0,-1 };
int dy[] = { 0,-1,-1 };
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int x = M - 1;
	int y = N - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int max = 0;
			for (int k = 0; k < 3; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx >= 0 && ny >= 0) {
					if (max < map[ny][nx])
						max = map[ny][nx];
				}
			}
			map[i][j] += max;
		}
	}
	cout << map[N - 1][M - 1]<<'\n';
}