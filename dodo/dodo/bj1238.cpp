#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX_STUDENT 1001
#define MAX_ROAD 10001
#define INF 10000000
int N, M, X;
int st_val[MAX_STUDENT][MAX_STUDENT];

int last_val[MAX_STUDENT];

vector<pair<int, int>> node_dist[MAX_ROAD];

void dijkstra(int n) {
	priority_queue<pair<int, int>> pq;
	st_val[n][n] = 0;
	pq.push(make_pair(n, 0));
	while (!pq.empty()) {
		int pos = pq.top().first;
		pq.pop();
		for (int i = 0; i < node_dist[pos].size(); i++) {
			int new_value = node_dist[pos][i].second + st_val[n][pos];
			int before_value = st_val[n][node_dist[pos][i].first];
			if (new_value < before_value) {
				pq.push(make_pair(node_dist[pos][i].first, node_dist[pos][i].second));
				st_val[n][node_dist[pos][i].first] = new_value;
			}
		}

	}
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		node_dist[from].push_back(make_pair(to, time));
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			st_val[i][j] = INF;
		}
	}
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}
	int max=  st_val[1][X] + st_val[X][1];
	for (int i = 2; i <= N; i++) {
		last_val[i] = st_val[i][X]+ st_val[X][i];
		if (max < last_val[i])
			max = last_val[i];
	}
	cout << max << endl;
	
}