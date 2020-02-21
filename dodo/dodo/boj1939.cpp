#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
/*
N���� ��, �� ���̿��� �ٸ��� �־� ���� ���������ִ�.
�ٸ����� �߷������� �ִ� �߷��ʰ� -> ������
�� ���� �̵����� �ű�� �ִ� ��ǰ���� �߷� �ִ밪

������ ��ġ���ִ� ���ǹ�ȣ 2���� ���������� �־���
1.
��ǰ�� �߷��� ���ؼ� �̺�Ž�� -> ���������� ���� �ȵǸ� ���� ���� ���� �Ǹ� ������ ����
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