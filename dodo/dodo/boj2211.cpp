#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;

/*
각 회선을 이용해서 통신 하는데 드는 시간의 합 만큼 든다
최소 개수의 회선만으로 복구, 패킷 전송속도 최소시간이 걸리는 것 
1번이 보안 설치할 컴퓨터
*/
typedef pair<int, int> pii;

typedef pair<int, pair<int, int>> pipii;

bool visit[1002] = { 0 };
int N, M;
vector<vector<pii>> node;
vector<pii> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	node.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back(pii(to, cost));
		node[to].push_back(pii(from, cost));
	}
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	visit[1] = true;
	for (int i = 0; i < node[1].size(); i++) {
		pq.push(pipii(node[1][i].second,pii(node[1][i].first,1)));
	}
	while (!pq.empty()){
		int cur = pq.top().second.first;
		int prev = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (visit[cur])
			continue;
		visit[cur] = true;
		ans.push_back(pii(prev, cur));
		for (int i = 0; i < node[cur].size(); i++) {
			if (visit[node[cur][i].first] == 0) {
				pq.push(pipii(cost + node[cur][i].second, pii(node[cur][i].first,cur)));
			}
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}