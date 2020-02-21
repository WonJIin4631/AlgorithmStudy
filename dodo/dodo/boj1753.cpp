#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

/*
방향 그래프 시작 지점에서 다른 모든 정점까지의 거리를 출력

prim알고리즘
*/
int V, E;
typedef pair<int, int> pii;
vector<vector<pii>> list;
int ans[20002];
int visit[20002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	list.resize(V + 1);
	for (int i = 1; i <= V; i++) {
		ans[i] = 987654321;
	}
	int st;
	cin >> st;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		list[from].push_back(pii(to, cost));
	}
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push(pii(0,st));
	while (!q.empty()) {
		int cur = q.top().second;
		int cost = q.top().first;
		q.pop();
		if (visit[cur] == 1)
			continue;
		visit[cur] = 1;
		ans[cur] = min(ans[cur], cost);
		for (int i = 0; i < list[cur].size(); i++) {
			int nCost = cost + list[cur][i].second;
			if (visit[list[cur][i].first] == 0) {
				q.push(pii( nCost,list[cur][i].first ));
			}
		}

	}
	for (int i = 1; i <= V; i++) {
		if (ans[i] == 987654321)
			cout << "INF" << '\n';
		else
			cout << ans[i] << '\n';
	}
	return 0;
}