#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
/*
N개의 섬, 섬 사이에는 다리가 있어 차가 지나갈수있다.
다리에는 중량제한이 있다 중량초과 -> 무너짐
한 번의 이동에서 옮길수 있는 물품들의 중량 최대값

공장이 위치해있는 섬의번호 2개가 마지막으로 주어짐
1.
물품의 중량에 대해서 이분탐색 -> 목적지까지 도착 안되면 왼쪽 범위 높게 되면 오른쪽 낮게
*/
typedef pair<int, int> pii;
int N, M;
int ans = 0;
int s_Island, e_Island;
vector<vector<pii>> list;
int visit[10002] = { 0 };
bool BFS(int weight) {
	queue<int> q;
	q.push(s_Island);
	visit[s_Island] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e_Island)
			return false;
		for (int i = 0; i < list[cur].size(); i++) {
			if (visit[list[cur][i].first] == 0) {
				if (list[cur][i].second >= weight) {
					visit[list[cur][i].first] = 1;
					q.push(list[cur][i].first);
				}
			}
		}
	}
	return true;
}
int main() {
	cin >> N >> M;
	list.resize(N + 1);
	int maxCost = 0;
	for (int i = 0; i < M; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		maxCost = max(maxCost, w);
		list[from].push_back(pii(to, w));
		list[to].push_back(pii(from, w));
	}
	cin >> s_Island >> e_Island;


	long long left = 1;
	long long right = maxCost;
	while (left <= right) {
		int mid = (left + right) / 2;
		memset(visit, 0, sizeof(visit));
		bool check = BFS(mid);
		if (check) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	cout << right << '\n';
	return 0;
}