#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_CITY 1001
#define MAX_BUS 100001
#define INF 100000000
int N, M, dist, From,To;

int c_dist[MAX_CITY] = { 0 };
vector<pair<int, int>> node_dist[MAX_BUS];

void dijkstra(int start) {
	priority_queue<pair<int, int>> dq;
	dq.push(make_pair(start, 0));
	int c, val;
	while (!dq.empty()) {
		c = dq.top().first;
		dq.pop();
		for (int i = 0; i < node_dist[c].size(); i++) {
			int before_val =  c_dist[node_dist[c][i].first];
			int new_val =  node_dist[c][i].second + c_dist[c];
			if (new_val < before_val) {
				dq.push(make_pair(node_dist[c][i].first, node_dist[c][i].second));
				c_dist[node_dist[c][i].first] = new_val;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		node_dist[from].push_back(make_pair(to, val));
	}
	for (int i = 0; i <= N; i++) {
		c_dist[i] = INF;
	}
	cin >> From>>To;
	c_dist[From] = 0;
	dijkstra(From);
	cout << c_dist[To]<<endl;
}