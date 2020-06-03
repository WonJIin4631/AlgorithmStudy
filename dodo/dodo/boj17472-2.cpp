#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321
struct Info {
	int x;
	int y;
};
struct Dest {
	int from;
	int to;
	int dist;

};
struct comp{
	bool operator()(Dest a, Dest b) {
		return a.dist > b.dist;
	}
};
int N, M;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int island_cnt;
int map[101][101];
bool visit[101][101];
vector<Info> island_edge[7];
bool check_Island[7];
int distMap[8][8];
int ans = 0;
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			distMap[i][j] = INF;
		}
	}
}
bool is_Inside(int x, int y) {
	if (x >= 0 && x < M&&y >= 0 && y < N)
		return true;
	return false;
}
void BFS(int x, int y, int idx) {
	queue<Info> q;
	q.push({ x,y });
	map[y][x] = idx;
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (is_Inside(nx, ny)) {
				if (map[ny][nx] == 0) {
					island_edge[idx].push_back({ cur.x,cur.y });
					break;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (is_Inside(nx, ny)) {
				if (!visit[ny][nx]) {
					if (map[ny][nx] == 1) {
						if (idx != 1) {
							map[ny][nx] = idx;
						}
						visit[ny][nx] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}
void div_island() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (!visit[i][j]) {
					island_cnt++;
					visit[i][j] = true;
					BFS(j, i, island_cnt);
					
				}
			}
		}
	}
}
Dest get_Dist(int x,int y,int dir,int idx) {
	int cnt = 0;
	bool flag = false;
	int to = 0;
	while (true){
		x += dx[dir];
		y += dy[dir];
		if (!is_Inside(x, y)) {
			flag = true;
			break;
		}
		if (map[y][x] == idx) {
			flag = true;
			break;
		}
		if (map[y][x] != 0) {
			to = map[y][x];
			break;
		}
		cnt++;
		if (map[y][x] == 0)
			continue;
		
	}
	if (flag)
		return{ idx,to,-1 };
	return{ idx,to,cnt };
}
void check_Dist() {
	for (int i = 1; i <= island_cnt; i++) {
		for (int j = 0; j < island_edge[i].size(); j++) {
			for (int d = 0; d < 4; d++) {
				Dest temp = get_Dist(island_edge[i][j].x, island_edge[i][j].y, d, i);
				
				if (temp.dist >= 2) {
					distMap[temp.to][temp.from] = distMap[temp.from][temp.to] = min(distMap[temp.from][temp.to], temp.dist);
				}
			}
		}
	}
}
void get_ans() {
	priority_queue<Dest, vector<Dest>,comp> pq;
	check_Island[1] = true;
	for (int i = 1; i <= island_cnt; i++) {
		if (distMap[1][i] != INF) {
			pq.push({ 1,i,distMap[1][i] });
		}
	}
	while (!pq.empty()){
		Dest cur = pq.top();
		pq.pop();
		if (check_Island[cur.to])
			continue;
		check_Island[cur.to] = true;
		ans += cur.dist;
		for (int i = 1; i <= island_cnt; i++) {
			if (distMap[cur.to][i] != INF) {
				if (!check_Island[i]) {
					pq.push({ cur.to, i, distMap[cur.to][i] });
				}
			}
		}
	}
	for (int i = 1; i <= island_cnt; i++) {
		if (!check_Island[i]) {
			ans = -1;
			break;
		}
	}
	cout << ans << '\n';
}
void solve() {
	init();
	div_island();
	check_Dist();
	get_ans();
}
int main() {
	solve();
	return 0;
}