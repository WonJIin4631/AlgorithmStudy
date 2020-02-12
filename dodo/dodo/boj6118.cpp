#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
1번 헛간에서  가장 멀리 있는 헛간번호(같은 거리일시 작은 헛간번호), 헛간 사이의 거리 , 같은 거리를 가지고 있는 헛간의개수 출력


*/
vector<int>  shed[20002];
int dist[20002] = { 0 };
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		shed[from].push_back(to);
		shed[to].push_back(from);
	}
	int ans=0, ans_dist=0, ans_cnt = 0;
	dist[1] = -1;
	queue<pair<int, int>> q;

	for (int i = 0; i < shed[1].size(); i++) {
		q.push(make_pair(shed[1][i], 1));
		dist[shed[1][i]] = 1;
	}
	while (!q.empty()){
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();
		if (d > ans_dist) {
			ans_cnt = 0;
			ans = cur;
			ans_dist = d;
		}
		if (d == ans_dist) {
			ans = min(ans, cur);
			ans_cnt++;
		}
		for (int i = 0; i < shed[cur].size(); i++) {
			if (dist[shed[cur][i]] == 0) {
				dist[shed[cur][i]] = d + 1;
				q.push(make_pair(shed[cur][i], d + 1));
			}
		}
	}
	cout << ans << ' ' << ans_dist << ' ' << ans_cnt << '\n';
	return 0;	
}