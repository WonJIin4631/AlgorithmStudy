#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int map[16+1][16+1];
int dir[3][2] = { {1,0},{1,1},{ 0,1 } };//오른 대각 아래
int state = 1;
int N;
int cnt = 0;

bool inPos(int s,int x, int y) {
	if (s == 2) {
		if (map[y][x] == 1 || map[y - 1][x] == 1 || map[y][x - 1] == 1)
			return false;
	}
	else if (s == 1 || s == 3) {
		if (map[y][x] == 1)
			return false;
	}
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	else
		return true;

}



void BFS(int state, int a, int b) {
	queue<pair<int,pair<int, int>>> q;
	q.push(make_pair(state, make_pair(a, b)));
	int s, x, y;
	while (!q.empty()) {
		s = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();
		if (x == N - 1 && y == N - 1) {
			cnt++;
		}
		else {
			if (s == 1) {
				if (inPos(1,x + 1, y))
					q.push(make_pair(1, make_pair(x + 1, y)));
				if (inPos(2,x + 1, y + 1))
					q.push(make_pair(2, make_pair(x + 1, y + 1)));
			}
			else if (s == 2) {
				if (inPos(1,x + 1, y))
					q.push(make_pair(1, make_pair(x + 1, y)));
				if (inPos(2,x + 1, y + 1))
					q.push(make_pair(2, make_pair(x + 1, y + 1)));
				if (inPos(3,x, y + 1))
					q.push(make_pair(3, make_pair(x, y + 1)));
			}
			else {
				if (inPos(2,x + 1, y + 1))
					q.push(make_pair(2, make_pair(x + 1, y + 1)));
				if (inPos(3,x, y + 1))
					q.push(make_pair(3, make_pair(x, y + 1)));
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
	BFS(state, 1, 0);
	cout << cnt << '\n';
}