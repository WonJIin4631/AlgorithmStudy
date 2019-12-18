#include<iostream>
#include<queue>
#include<functional>
#include<math.h>
#include<string.h>
using namespace std;
int swanPos[2][2];
char map[1501][1501];
int visit[1501][1501] = { 0, };
int meltDay[1501][1501] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int R, C;
struct node
{
	int x;
	int y;
	int day;
	node(int x, int y, int day) :x(x), y(y), day(day) {}
};

struct cmp {
	bool operator() (node a, node b) {
		return a.day > b.day;
	}
};
int solution() {
	priority_queue <node, vector<node>, cmp> pq;
	pq.push(node(swanPos[0][1], swanPos[0][0], 0));
	visit[swanPos[0][0]][swanPos[0][1]] = 1;
	while (!pq.empty())
	{
		node cur = pq.top();
		pq	.pop();
		if (swanPos[1][1] == cur.x && swanPos[1][0] == cur.y) {
			return cur.day;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if ((nx >= 0 && nx < C && ny >= 0 && ny < R) && visit[ny][nx] == 0) {
				visit[ny][nx] = 1;
				pq.push(node(nx, ny, max(cur.day, meltDay[ny][nx])));
			}
		}
	}
}
void melt() {
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.' || map[i][j] == 'L') {
				visit[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty())
	{
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			meltDay[y][x] = cnt;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if ((nx >= 0 && nx < C && ny >= 0 && ny < R) && visit[ny][nx] == 0) {
					visit[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
		cnt++;
	}
	memset(visit, 0, sizeof(visit));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swanPos[cnt][0] = i;
				swanPos[cnt][1] = j;
				cnt++;
			}
		}
	}
	melt();
	cout << solution()<<'\n';
}