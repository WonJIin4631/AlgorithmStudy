#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info{
	int x;
	int y;
	int size;
};
int N, M;
int starCnt = 0;
char map[101][101];
bool visit[101][101] = { 0 };
vector<Info> ans;
bool ansFlag;
int minDist;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void solve(int cnt,int idx) {
	if (ansFlag)
		return;
	if (cnt == 0||idx==N*M-1) {
		
		if(cnt==0){
			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].size << '\n';
			}
		}
		else {
			cout << -1 << '\n';
		}
		ansFlag = true;

		return;
	}
	int x = idx % M;
	int y = idx / M;

	int tempCnt = 0;
	if (map[y][x] == '*') {
		bool flag = false;
		int cDist = 0;
		for (int dd = 1; dd <= minDist; dd++) {
			for (int i = 0; i < 4; i++) {
				int nx = x + (dx[i] * dd);
				int ny = y + (dy[i] * dd);
				if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
					if (map[ny][nx] == '.') {
						flag = true;
						break;
					}
				}
				else {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			cDist = dd;
		}

		if (cDist > 0) {
			if (visit[y][x] == false) {
				tempCnt++;
				visit[y][x] = true;;
			}
			for (int dd = 1; dd <= cDist; dd++) {
				for (int i = 0; i < 4; i++) {
					int nx = x + (dx[i] * dd);
					int ny = y + (dy[i] * dd);
					if (visit[ny][nx] == false) {
						visit[ny][nx] = true;
						tempCnt++;
					}
				}
				ans.push_back({ y + 1,x + 1,dd });
			}
		}
	}
	solve(cnt-tempCnt, idx + 1);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*')
				starCnt++;
		}
	}
	minDist = min(N, M);
	minDist /= 2;
	solve(starCnt, 0);
	return 0;
}