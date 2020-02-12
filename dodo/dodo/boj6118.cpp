#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
1�� �갣����  ���� �ָ� �ִ� �갣��ȣ(���� �Ÿ��Ͻ� ���� �갣��ȣ), �갣 ������ �Ÿ� , ���� �Ÿ��� ������ �ִ� �갣�ǰ��� ���


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