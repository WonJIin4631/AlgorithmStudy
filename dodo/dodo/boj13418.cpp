#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
/*
����� �׻� �Ա����� �ϰ� ��� �ǹ��� Ž���ؾߵ�  �ǹ��� �湮�Ҷ� ������, ������ 2���� ���� �ִ�.(0 ������ ,1 ������)
�Ƿε��� ������ K�� �ö����� K^2�̴�
��� �ǹ��� Ž�������� �Ƿε��� ���� �����Ͱ� ū���� ���̰�
�Ա��� �׻� 1�� �ǹ��� ����Ǿ� �ִ�.

2�� Ž�� �Ƿε��� �������� Ŭ���� ����Ž��
�������� ������ �ľ� -> disjointset
���� �������� ������ �ش� �ǹ������� ���������� ���ؼ� ť�� ����
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