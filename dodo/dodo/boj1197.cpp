#include<iostream>
#include<queue>
#include<functional>
using namespace std;
/*
모든 정점 연결된 그래프 중 가중치가 가작 적은 값 출력
prim ,kruskal 둘중에 하나 사용
prim 사용
간선의 개수가 작은 경우에는 크루스칼 알고리즘을, 간선의 개수가 많은 경우에는 프림 알고리즘 사용 하는게 좋음
*/
typedef pair<int, int> pii;
int visit[10002] = { 0 };
vector<pii> node[10002];
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		node[from].push_back(pii(to, dist));
		node[to].push_back(pii(from, dist));
	}
	priority_queue<pii, vector<pii>, greater<pii> >pq;
	
	for (int i = 0; i < node[1].size(); i++) {
		pq.push(make_pair(node[1][i].second, node[1][i].first));
	}
	visit[1] = 1;
	while (!pq.empty()){
		int to = pq.top().second;
		int	val = pq.top().first;
		pq.pop();
		if (visit[to]==1)
			continue;
		ans += val;
		visit[to] = 1;
		for (int i = 0; i < node[to].size(); i++) {
			pq.push(make_pair(node[to][i].second, node[to][i].first));
		}
	}
	cout << ans << '\n';
	return 0;
}