#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
/*
�л��� N,ģ�� ���� �� M,������ �ִµ� K

���� ����Ʈ�� �̿��ؼ� ģ�������� �Ϳ� ���� ����Ž���Ѵ�. ģ�����踦 ���ед�.
���� �ִ� �ݾ׿��� ù��° ģ������ ������ ģ������ ���� ģ���������� Ȯ���ϸ� �ƴϸ� ���� �����ϰ� ģ���� �Ѵ�.
ģ�� ���迡���� ���� ���� �ݾ��� ����� ģ���� �ξ�ߵ�
*/

int N, M, K;
int money[10002];
int parent[10002];
int minMoney[10002];
int visit[10002] = { 0 };
vector<vector<int>> v;

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> money[i];
		parent[i] = i;
		minMoney[i] = money[i];
	}
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		for (int j = 0; j < v[i].size(); j++) {
			q.push(v[i][j]);
			visit[v[i][j]] = 1;
		}
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			parent[cur] = i;
			minMoney[i] = min(minMoney[i], money[cur]);
			for (int j = 0; j < v[cur].size(); j++) {
				if (visit[v[cur][j]] == 0) {
					visit[v[cur][j]] = 1;
					q.push(v[cur][j]);
				}
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[parent[i]] == 0) {
			visit[parent[i]] = 1;
			ans += minMoney[parent[i]];
		}
	}
	if (ans > K)
		cout << "Oh no" << '\n';
	else
		cout << ans << '\n';
	return 0;
}