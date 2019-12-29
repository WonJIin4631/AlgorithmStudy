#include<iostream>
#include<queue>
using namespace std;
int N,M;
int st, en;
int map[102][102];
int visit[102];
queue<pair<int, int>> q;


void solve() {
	for (int i = 1; i <= N; i++) {
		if (map[st][i] == 1) {
			q.push(make_pair(1, i));
			visit[i] = 1;
		}
	}
	while (!q.empty()){
		int consu = q.front().first;
		int node = q.front().second;
		q.pop();
		if (node == en) {
			cout << consu << '\n';
			return;
		}
		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				if (map[node][i] == 1) {
					visit[i] = 1;
					q.push(make_pair(consu + 1, i));
				}
			}
		}
	}
	cout << -1 << '\n';
	return;
}
int main() {
	cin >> N;
	cin >> st >> en;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	solve();
	return 0;
}