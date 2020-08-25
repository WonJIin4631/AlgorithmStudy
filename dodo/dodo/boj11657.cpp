#include<iostream>
#include<vector>
using namespace std;
#define INF 987654321

int N, M;
long long Dist[510];
struct Info{
	int from;
	int to;
	int cost;
};
vector<Info> Edge;

void solve(){
	Dist[1] = 0;
	for (int i = 1; i <= N - 1; i++){
		for (int j = 0; j < Edge.size(); j++){
			int from = Edge[j].from;
			int to = Edge[j].to;
			int cost = Edge[j].cost;
			if (Dist[from] == INF) 
				continue;

			if (Dist[to] > Dist[from] + cost)
				Dist[to] = Dist[from] + cost;
		}
	}

	for (int i = 0; i < Edge.size(); i++){
		int from = Edge[i].from;
		int to = Edge[i].to;
		int cost = Edge[i].cost;
		if (Dist[from] == INF) 
			continue;
		if (Dist[to] > Dist[from] + cost){
			cout << -1 << '\n';
			return;
		}
	}

	for (int i = 2; i <= N; i++){
		if (Dist[i] == INF)
			cout << -1 << '\n';
		else cout << Dist[i] << '\n';
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		Dist[i] = INF;
	for (int i = 0; i < M; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		Edge.push_back({ from,to,cost });
	}
	solve();
	return 0;
}
