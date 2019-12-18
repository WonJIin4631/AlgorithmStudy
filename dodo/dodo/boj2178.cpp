#include<iostream>
#include<string>
#include<string.h>
#include<queue>
using namespace std;

char map[101][101];
int visit[101][101];
int ans = 987654321;
int N, M;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };



void BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visit[0][0] = 1;
	while (!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int can = q.front().second;
		q.pop();
		if (x == M - 1 && y == N - 1) {
			if (ans > can)
				ans = can;
		}
		if (ans < can)
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[ny][nx] == 0 && map[ny][nx] == '1') {
				visit[ny][nx] = 1;
				q.push(make_pair(make_pair(nx, ny), can + 1));
			}
		}
	}

}


int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	BFS();
	cout << ans << '\n';
}