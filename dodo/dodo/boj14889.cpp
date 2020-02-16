#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[21][21];
int ans = 987654321;
int visit[21];
int N;
int team1[11];
int team2[11];
void solve(int idx, int cnt) {
	if (cnt == N / 2) {
		int stidx = 0;
		int linkidx = 0;
		int stScore = 0;
		int linkScore = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i] == 1)
				team1[stidx++] = i;
			else
				team2[linkidx++] = i;
		}
		//중복 점수 확인 되는것을 방지하기 위해서 반만큼 확인 
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				stScore+= map[team1[i]][team1[j]];
				stScore += map[team1[j]][team1[i]];
				linkScore += map[team2[i]][team2[j]];
				linkScore += map[team2[j]][team2[i]];
			}
		}
		ans = min(ans, abs(stScore - linkScore));
		return;
	}
	for (int i = idx; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			solve(i+1, cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve(0, 0);
	cout << ans << '\n';
}