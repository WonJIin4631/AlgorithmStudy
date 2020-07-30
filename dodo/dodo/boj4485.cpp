#include<iostream>
#include<queue>
using namespace std;

struct Info{
	int cost;
	int x;
	int y;
};
struct comp{
	bool operator()(Info a, Info b) {
		return a.cost > b.cost;
	}
};
int map[126][126];
bool visit[126][126] = { 0 };
priority_queue<Info, vector<Info>, comp> pq;
int N;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool isIn(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
int main() {
	int problemIdx = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true){
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}
		pq.push({ map[0][0],0,0 });
		visit[0][0] = true;
		bool flag = false;
		while (!pq.empty()){
			Info cur = pq.top();
			pq.pop();
			if (flag)
				continue;
			if (cur.x == N - 1 && cur.y == N - 1) {
				cout << "Problem " << problemIdx << ": " << cur.cost << '\n';
				flag = true;
				continue;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny)) {
					if (visit[ny][nx] == false) {
						pq.push({ cur.cost + map[ny][nx],nx,ny });
						visit[ny][nx] = true;
					}
				}
			}
		}
		problemIdx++;
	}
	return 0;
}