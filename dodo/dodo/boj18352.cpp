#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> edge[300001];
bool visit[300001];
int N, M, K, X;
vector<int> ans;
int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
	}
	queue<int> q;
	int dist = 0;
	visit[X] = 1;
	q.push(X);
	while (!q.empty()) {
		if (dist == K) {
			while (!q.empty()){
				ans.push_back(q.front());
				q.pop();
			}
			break;
		}
		int qsz = q.size();
		for (int i = 0; i < qsz; i++) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < edge[cur].size(); j++) {
				if (visit[edge[cur][j]] == 0) {
					q.push(edge[cur][j]);
					visit[edge[cur][j]] = 1;
				}
			}
		}
		dist++;
	}
	if (ans.size() == 0)
		cout << -1 << '\n';
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	}
	return 0;
}