#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int N, M;
bool maze[100+1][100+1];
int mazecount[100+1][100+1];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//left,right,up,down
queue<pair<int,int>> que;

bool inside(int n1, int n2) {
	if (n1 >= 0 && n1 < N &&n2 >= 0 && n2 < M)
		return true;
	else
		return false;
}

void BFS() {
	que.push(make_pair(0,0));
	mazecount[0][0] = 1;
	int first_x, first_y;
	maze[0][0] = 0;
	while (!que.empty()) {
		first_x = que.front().first;
		first_y = que.front().second;
		que.pop();
		if ((first_x == N - 1) && (first_y == M - 1)) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int next_x = first_x + dir[i][0];
			int next_y = first_y + dir[i][1];
			if (inside(next_x, next_y) && maze[next_x][next_y] == 1) {
				que.push(make_pair(next_x, next_y));
				maze[next_x][next_y] = 0;
				mazecount[next_x][next_y] = mazecount[first_x][first_y] + 1;
			}
		}
	}	
}

int main() {
	scanf_s("%d %d", &N,&M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			scanf_s("%1d", &num);
			if (num == 1)
				maze[i][j] = true;
		}
	}
	BFS();
	printf("%d\n", mazecount[N-1][M-1]);
}