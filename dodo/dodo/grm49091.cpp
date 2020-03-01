#include <iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

int N, M;
typedef pair<int, int> pii;
int ans;
int main() {
	cin >> N >> M;
	vector<vector<pii>> list;
	list.resize(N + 1);
	int cityDist[100002];
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		list[from].push_back(pii(to, cost));
	}
	for (int i = 1; i <= N; i++) {
		cityDist[i] = 987654321;
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < list[1].size(); i++) {
		pq.push(pii(list[1][i].second, list[1][i].first));
	}
	while (!pq.empty()) {
		int curCity = pq.top().second;
		int curDist = pq.top().first;
		cityDist[curCity] = curDist;
		pq.pop();
		if (curCity == N) {
			ans = curDist;
			break;
		}
		for (int i = 0; i < list[curCity].size(); i++) {
			if (cityDist[list[curCity][i].first]>list[curCity][i].second + curDist)
				pq.push(pii(list[curCity][i].second + curDist, list[curCity][i].first));
		}
	}
	cout << ans << '\n';
	if (ans == 0) {
		cout << "go home" << '\n';
	}
	else
		cout << ans << '\n';
	return 0;
}