#include<iostream>
#include<queue>
using namespace std;

int N, M;
bool maze[100 + 1][100 + 1];
int mazecount[100 + 1][100 + 1];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
queue<pair<int, int>> q;

bool isin(int y, int x) {
	if (y >= 0 && y < N &&x >= 0 && x < M)
		return true;
	return false;
}

void BFS() {
	q.push(make_pair(0, 0));
	mazecount[0][0] = 1;
	int first_x, first_y;
	maze[0][0] = 0;
	while (!q.empty()) {
		first_x = q.front().first;
		first_y = q.front().second;
		q.pop();
		if ((first_x == N - 1) && (first_y == M - 1)) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_x = first_x + dir[i][0];
			int next_y = first_y + dir[i][1];
			if (isin(next_x, next_y) && maze[next_x][next_y] == 1) {
				q.push(make_pair(next_x, next_y));
				maze[next_x][next_y] = 0;
				mazecount[next_x][next_y] = mazecount[first_x][first_y] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (num == 1)
				maze[i][j] = true;
		}
	}
	BFS();
	cout << mazecount[N - 1][M - 1] << '\n';
	return 0;
}