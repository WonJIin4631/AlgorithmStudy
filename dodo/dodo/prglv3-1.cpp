#include <iostream>
#include <vector>
#include<queue>
#include<functional>
#include<iostream>
using namespace std;

typedef pair<int, int> pii;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 1;
	vector<pii> node[52];
	for (int i = 0; i < road.size(); i++) {
		int from = road[i][0];
		int to = road[i][1];
		int dist = road[i][2];
		node[from].push_back(pii(to, dist));
		node[to].push_back(pii(from, dist));
	}
	bool visit[52] = { false };
	priority_queue < pii, vector<pii>, greater<pii>> pq;
	visit[1] = true;
	for (int i = 0; i < node[1].size(); i++) {
		pq.push(pii(node[1][i].second, node[1][i].first));
	}
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = pq.top().first;
		pq.pop();
		if (visit[cur])
			continue;
		if (dist>K)
			continue;
		visit[cur] = true;
		if (dist <= K)
			answer++;
		for (int i = 0; i< node[cur].size(); i++) {
			pq.push(pii(dist + node[cur][i].second, node[cur][i].first));
		}
	}
	return answer;
}
