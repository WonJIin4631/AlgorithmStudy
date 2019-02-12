#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

#define MAX_V  20001
#define MAX_E  300001
#define INF  100000000
int V, E, K;
int startN;
int dist[MAX_V];

vector<pair<int, int>> node_dist[MAX_E];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start,0));
	while (!pq.empty()) {
		int pos = pq.top().first;
		int cost = -1 * pq.top().first;
		pq.pop();
		for (int i = 0; i < node_dist[pos].size(); i++) {
			int new_val =  node_dist[pos][i].second +dist[pos];
			int before_val = dist[node_dist[pos][i].first];
			if (new_val < before_val) {
				pq.push(make_pair(node_dist[pos][i].first,new_val));
				dist[node_dist[pos][i].first] = new_val;
			}
		}
	}

}
int main() {
	scanf("%d %d %d", &V, &E, &K);
	for (int i = 0; i < E; i++) {
		int from, to, distValue;
		scanf("%d %d %d", &from,&to,&distValue);
		node_dist[from].push_back(make_pair(to, distValue));
	}
	
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[K] = 0;
	dijkstra(K);
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF)
			printf("%d", dist[i]);
		else
			printf("INF");;
	}
	
}