#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
방향성 없는 그래프 주어짐, 연결요소 개수 구하기

1~N개의 정점 M개의간선
처cnt 변수를 통해 연결요소 개수 를 파악
방문했는지를 파악하는 visit배열을 선언
1번 부터 방문하지 않은 노드이면 BFS탐색하면서 탐색 된 노드의 visit에 현재 cnt값을 넣음 
N번까지 방문후 cnt 값을 출력

주의 . 정점이 연결된 엣지가 없어도 연결요소이다.
*/
int N, M;
int visit[1002] = { 0 };
vector<int> node[1002];
int cnt = 0;
void BFS(int stNum) {
	queue<int> q;
	visit[stNum] = cnt;
	for (int i = 0; i < node[stNum].size(); i++) {
		if (visit[node[stNum][i]] == 0) {
			q.push(node[stNum][i]);
			visit[node[stNum][i]] = cnt;
		}
	}
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			if (visit[node[cur][i]] == 0) {
				q.push(node[cur][i]);
				visit[node[cur][i]] = cnt;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		node[from].push_back(to);
		node[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			cnt++;
			BFS(i);
		}
	}
	cout << cnt << '\n';
	return 0;
}