#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Info {
	int x;
	int y;
};

int N;
int M;
int stFuel;
int Map[22][22];
int stmap[22][22];
vector<int> endmap[22][22];
bool visit[22][22];
int distMap[402][402];
Info sonim[402];
Info curPos;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isIn(int x, int y) {
	return x >= 1 && x <= N&&y >= 1 && y <= N;
}

void init() {
	cin >> N >> M >> stFuel;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];
	int x, y;
	cin >> y >> x;
	curPos = { x,y };
	for (int i = 1; i <= M; i++) {
		cin >> y >> x;
		stmap[y][x] = i;
		sonim[i] = { x,y };
		cin >> y >> x;
		endmap[y][x].push_back(i);
	}
}
void BFS(int idx,int x,int y) {
	visit[y][x] = true;
	queue<Info> q;
	q.push({ x,y });
	int time = 0;
	while (!q.empty()){
		int qsz = q.size();
		for (int qq = 0; qq < qsz; qq++) {
			Info cur = q.front();
			q.pop();
			if (endmap[cur.y][cur.x].size() != 0) {
				for(int i=0;i<endmap[cur.y][cur.x].size();i++)
					distMap[idx][endmap[cur.y][cur.x][i]] = time;
			}
			if (cur.x == curPos.x&&cur.y == curPos.y) {
				distMap[idx][0] = time;
			}
			for (int d = 0; d < 4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if (isIn(nx, ny)) {
					if (Map[ny][nx] == 0 && visit[ny][nx] == false) {
						q.push({ nx,ny });
						visit[ny][nx] = true;
					}
				}
			}
		}
		time++;
	}
	memset(visit, 0, sizeof(visit));
}
void getDist() {
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			distMap[i][j] = 9887654321;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (stmap[i][j] != 0) {
				BFS(stmap[i][j], j, i);
			}
		}
	}
}
void solve() {
	getDist();
	bool check[402] = { 0 };
	int curIdx = 0;
	int cnt = 0;
	bool flag = true;
	while (true){
		if (stFuel <= 0)
			break;
		if (cnt == M)
			break;
		int minDist = 987654321;
		int tempIdx;
		for (int i = 1; i <= M; i++) {
			if (i == curIdx)
				continue;
			if (check[i] == false) {
				if (minDist > distMap[i][curIdx]) {
					minDist = distMap[i][curIdx];
					tempIdx = i;
				}
				else if (minDist == distMap[i][curIdx]) {
					if (sonim[tempIdx].y > sonim[i].y) {
						tempIdx = i;
					}
					else if (sonim[tempIdx].y == sonim[i].y) {
						if (sonim[tempIdx].x > sonim[i].x)
							tempIdx = i;
					}
				}
			}
		}
		if (stFuel - minDist > 0) {
			curIdx = tempIdx;
			check[curIdx] = true;
			stFuel -= minDist;
			if (stFuel - distMap[curIdx][curIdx] >= 0) {
				stFuel += distMap[curIdx][curIdx];
				cnt++;
			}
			else {
				flag = false;
				break;
			}
		}
		else {
			flag = false;
			break;
		}
	}
	if (cnt != M)
		flag = false;
	if (flag)
		cout << stFuel << '\n';
	else
		cout << -1 << '\n';
}
int main() {
	init();
	solve();
	
	return 0;
}