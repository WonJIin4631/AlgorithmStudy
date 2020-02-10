#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
���⼺ ���� �׷��� �־���, ������ ���� ���ϱ�

1~N���� ���� M���ǰ���
ócnt ������ ���� ������ ���� �� �ľ�
�湮�ߴ����� �ľ��ϴ� visit�迭�� ����
1�� ���� �湮���� ���� ����̸� BFSŽ���ϸ鼭 Ž�� �� ����� visit�� ���� cnt���� ���� 
N������ �湮�� cnt ���� ���

���� . ������ ����� ������ ��� �������̴�.
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