#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
/*
NxN 크기 물고기 M마리와 아기상어 상어는 1초에 상하좌우 1칸을 움직일수 있다. 자신의 크기보다 큰 물고기가 있는 칸은 지나갈수 없다.
나머지 칸은 지나갈수 있다. 아기상어는 자신의 크기보다 작은애만 먹을수 있다. 같은 크기 물고기는 지나갈수 있다
먹을수 있는 물고기가 1마리면 해당 물고기먹으러감
1마리 이상이면 거리가 가까운 물고기를 먹는다. 거리가 가까운 물고기가 2마리 이상이면 가장위-> 가장 왼쪽 물고기를 먹는디.
상어는 자기와 같은 크기의 물고기와  수만큼 물고기를 먹게되면 1증가.

현재 크기와 같은 물고기가 있는지 파악함 없다면 종료
있다면 조건에 맞게 물고기를 먹는다. 가는길에 자신의 크기보다 작은 물고기가 있으면 먹고 이동함

물고기의 크기를 기준으로 배열에 저장 -> 저장할때 물고기의 좌표를 저장
현재 남은 물고기의 수와 먹었던 물고기 정보 저장
주어진 조건에 맞게 시뮬
*/

typedef pair<int, int> pii;
int map[22][22] = { 0 };
int visit[22][22] = { 0 };
int leftFish[7] = { 0 };
vector<pii> fish[7];
int N;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int sx, sy;
int s_sz = 2;
int s_cnt = 0;
int time = 0;

int c_fx;
int c_fy;
int findF(int x,int y) {
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	q.push(pii(y, x));
	visit[y][x] = 1;
	vector<pii> f;
	int can =0;
	bool flag = false;
	while (!q.empty()){
		//이동시간 기준으로 탐색
		int qsz = q.size();
		//cout << qsz << '\n';
		if (flag) {
			while (!q.empty()){
				q.pop();
			}
			break;
		}
		for (int i = 0; i < qsz; i++) {
			int cx = q.front().second;
			int cy = q.front().first;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
					if (visit[ny][nx] == 0 ){
						//물고기가 없는칸
						if (map[ny][nx] <= s_sz) {
							visit[ny][nx] = 1;
							q.push(pii(ny, nx));
						}
						//먹을수 있는 물고기칸
						if (map[ny][nx] > 0 && map[ny][nx] < s_sz) {
							f.push_back(pii(ny, nx));
						}
					}
				}
			}
		}
		if (f.size() > 0) {
			//정렬하여 첫번째 물고기 선택
			sort(f.begin(), f.end());
			c_fx = f[0].second;
			c_fy = f[0].first;
			flag = true;
		}
		can++;
	}
	f.clear();
	if (flag)
		return can;
	else
		return -1;
}
int solve() {
	int time = 0;
	while (true) {
		bool flag = true;
		//먹을 물고기가 남아 있는지 확인
		for (int i = 1; i <= s_sz; i++) {
			if (leftFish[i] > 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			break;
		//먹을 물고기 찾기
		int dist;
		dist = findF(sx, sy);
		//먹을게 남아있지만 먹을수 없는경우
		if (dist == -1)
			break;
		//자신의 크기보다 작으면 사이즈 증가
		if (map[c_fy][c_fx] <= s_sz) {
			s_cnt++ ;
			if (s_cnt == s_sz) {
				s_cnt = 0;
				s_sz++;
			}
		}
		//이동한 칸만큼 시간증가
		time += dist;
		//먹은 물고기 수감소
		leftFish[map[c_fy][c_fx]]--;
		map[c_fy][c_fx] = 0;
		//상어위치 초기화
		sx = c_fx;
		sy = c_fy;
	}
	return time;
}
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			if (n == 0)
				continue;
			if (n == 9) {
				sx = j, sy = i;
				continue;
			}
			map[i][j] = n;
			leftFish[n]++;
			fish[n].push_back(pii(i, j));
		}
	}
}
int main() {
	init();
	cout << solve() << '\n';
	return 0;
}