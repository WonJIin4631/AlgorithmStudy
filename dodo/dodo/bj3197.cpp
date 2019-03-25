#include<iostream>
#include<queue>
#include<functional>
#include<math.h>
using namespace std;
#define MAX_SIZE 1501
int swanPos[2][2];
char map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };
int meltDay[MAX_SIZE][MAX_SIZE] = { 0, };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
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
	priority_queue <node,vector<node>,cmp> pq;
	pq.push(node(swanPos[0][0], swanPos[0][1], 0));
	visit[swanPos[0][0]][swanPos[0][1]]=1;
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();
		if (swanPos[1][0] == cur.x && swanPos[1][1] == cur.y) {
			return cur.day;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if ((nx >= 0 && nx < R && ny >= 0 && ny < C) && visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				pq.push(node(nx, ny, max(cur.day, meltDay[nx][ny])));
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
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			meltDay[x][y] = cnt;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];	
				int ny = y + dy[j];
				if ((nx >= 0 && nx < R && ny >= 0 && ny < C) && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		cnt++;
	}	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visit[i][j] = 0;
		}
	}
}


int asd(int a) {
	if (a == 1)
		return a;
	else
		return 0;
}
int main() {
	cin >> R >> C;
	int cnt = 0;
	for(int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				swanPos[cnt][0]=i;
				swanPos[cnt][1]=j;
				cnt++;
			}
		}
	}
	melt();
	cout<<solution();
	
}