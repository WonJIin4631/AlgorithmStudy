#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int N, M;
int visit[32002];
vector<int> arr[32002];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		visit[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		visit[cur]--;
		cout << cur << ' ';
		for (int i = 0; i < arr[cur].size(); i++) {
			visit[arr[cur][i]]--;
			if (visit[arr[cur][i]] == 0) {
				pq.push(arr[cur][i]);
			}
		}
	}
}