#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
int map[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
typedef pair<int, int> pii;
vector<pii> v;
int nt = 0;
int ft = 0;
int wt = 0;
int solve() {
	queue<pii> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(pii(v[i].first, v[i].second));
	}
	int day = 0;
	while (!q.empty())	{
		day++;
		int qsz = q.size();
		for (int t = 0; t < qsz; t++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < M&&ny >= 0 && ny < N) {
					if (map[ny][nx] == 0) {
						wt--;
						map[ny][nx] = 1;
						q.push(pii(ny, nx));
					}
				}
			}
		}
	}
	if (wt != 0)
		return -1;
	return day-1;
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				nt++;
			else if (map[i][j] == 1) {
				ft++;
				v.push_back(pii(i, j));
			}
			else
				wt++;

		}
	}
	if ((nt + ft) == N*M)
		cout << 0 << '\n';
	else if (ft == 0)
		cout << -1 << '\n';
	else {
		cout << solve() << '\n';
	}
	return 0;
}