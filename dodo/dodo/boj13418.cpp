#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
/*
출발은 항상 입구에서 하고 모든 건물을 탐색해야됨  건물을 방문할때 오르막, 내리막 2가지 길이 있다.(0 오르막 ,1 내리막)
피로도는 오르막 K개 올랐을때 K^2이다
모든 건물을 탐방했을때 피로도가 제일 적은것과 큰것의 차이값
입구는 항상 1번 건물과 연결되어 있다.

2번 탐색 피로도가 적을때와 클때로 완전탐색
시작점이 같은지 파악 -> disjointset
만약 시작점이 같을때 해당 건물까지의 오르막수를 비교해서 큐에 넣음
*/
int N, M;
int parent[1002];

int get_parent(int a) {
	if (a == parent[a])
		return a;
	else
		return parent[a]= get_parent(parent[a]);
}
bool sameParent(int a, int b) {
	if (get_parent(a) == get_parent(b))
		return true;
	else
		return false;
}
void merge(int a, int b) {
	int pa = parent[a];
	int pb = parent[b];
	if (pa == pb)
		return;
	if (pa < pb)
		pb = pa;
	else
		pa = pb;
}
int main() {
	cin >> N >> M;
	vector < pair<int, pair<int, int>>> v;
	v.resize(N + 1);
	for (int i = 0; i < M+1; i++) {
		int from, to, gil;
		cin >> from >> to >> gil;
		v.push_back(make_pair(gil, make_pair(from, to)));
	}
	for (int i = 0; i<=N; i++) {
		parent[i] = i;
	}
	int minVal, maxVal;
	sort(v.begin(), v.end(),greater<>());
	int mincnt = 0;
	for (int i = 0; i < v.size(); i++) {
		int from = v[i].second.first;
		int to = v[i].second.second;
		if (v[i].first == 1) {
			if (!sameParent(from, to)) {
				merge(from, to);
				mincnt++;
			}
		}
	}
	minVal = (N - mincnt)*(N- mincnt);
	int maxcnt = 0;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	sort(v.begin(), v.end(), less<>());
	for (int i = 0; i < v.size(); i++) {
		int from = v[i].second.first;
		int to = v[i].second.second;
		if (v[i].first == 0) {
			if (!sameParent(from, to)) {
				merge(from, to);
				maxcnt++;
			}
		}
	}
	maxVal = maxcnt*maxcnt;
	cout << maxVal - minVal << '\n';
	return 0;
}