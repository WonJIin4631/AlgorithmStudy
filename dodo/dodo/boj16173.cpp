#include<iostream>
#include<queue>
using namespace std;

int N;
int map[4][4];
bool check[4][4] = { 0 };
int dx[] = { 0,1 };
int dy[] = { 1,0 };
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	check[0][0] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j]) {
				for (int d = 0; d < 2; d++) {
					int nx = j + dx[d] * map[i][j];
					int ny = i + dy[d] * map[i][j];
					if (isIn(nx, ny)) {
						check[ny][nx] = true;
					}
				}
			}
		}
	}
	if (check[N-1][N-1])
		cout << "HaruHaru" << '\n';
	else
		cout << "Hing" << '\n';
	return 0;
}