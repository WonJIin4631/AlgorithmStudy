#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int N, M, V;
int map[1001][1001];
int visit[10001];

void DFS(int n) {
	visit[n] = 1;
	cout << n+1 << ' ';
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0 && map[n][i] == 1) {
			visit[i] = 1;
			DFS(i);
		}
	}
}


void BFS(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		cout << node+1 << ' ';
		for (int i = 0; i < N; i++) {
			if (visit[i] == 0 && map[node][i] == 1) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[b - 1][a - 1] = 1;
	}
	DFS(V - 1);
	memset(visit, 0, sizeof(visit));
	cout << '\n';
	BFS(V - 1);
}