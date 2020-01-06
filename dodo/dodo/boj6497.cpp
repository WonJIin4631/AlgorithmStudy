#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstdio>
#include<cstring>
using namespace std;

/*
최소스패닝트리MST
prim
간선이 많으면 프림이 적합

kruskal
간선이 적으면 크루스칼이 적합

*/

typedef pair<int, int> pii;

bool visit[200001];
vector<vector<pii>> edge;
int N, M;

long long on_cost = 0;
long long total_cost = 0;
void prim(int start) {
	visit[start] = true;

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (int i = 0; i < edge[start].size(); i++) {
		int to = edge[start][i].first;
		int cost = edge[start][i].second;
		pq.push(pii(cost, to));
	}
	while (!pq.empty()){
		int cur = pq.top().second;
		int curcost = pq.top().first;
		pq.pop();
		if (visit[cur])
			continue;
		visit[cur] = true;
		on_cost += curcost;	

		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int nextcost = edge[cur][i].second;
			pq.push(pii(nextcost, next));
		}
	}
}

int main() {
	while (true)
	{
		int M, N;
		cin >> M >> N;
		edge.resize(M + 1);
		if (M == 0 && N == 0)
			break;
		for (int i = 0; i < N; i++) {
			int from, to, val;
			cin >> from >> to >> val;
			total_cost += val;
			edge[from].push_back(pii(to, val));
			edge[to].push_back(pii(from, val));
		}
		prim(0);
		long long ans = total_cost - on_cost;
		cout << ans << '\n';
		total_cost = 0;
		on_cost = 0;
		edge.clear();
		memset(visit, 0, sizeof(visit));
	}	
	return 0;
}