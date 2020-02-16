#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1번 컴퓨터에서 연결된 컴퓨터들은 웜바이러스에 걸림 
1번을 통해 바이러스 걸린 컴퓨터 수를 출력

1번부터 연결되어있는 노드를 순차 탐색 
*/

int main() {
	int N, M;
	int ans = 0;
	cin >> N >> M;
	vector<vector<int>> node;
	int visit[102] = { 0 };
	node.resize(N+1);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		node[from].push_back(to);
		node[to].push_back(from);
	}
	visit[1] = 1;
	queue<int> q;
	for (int i = 0; i < node[1].size(); i++) {
		visit[node[1][i]] = 1;
		q.push(node[1][i]);
		ans++;
	}
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			if (visit[node[cur][i]] == 0) {
				visit[node[cur][i]] = 1;
				q.push(node[cur][i]);
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}