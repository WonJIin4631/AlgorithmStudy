#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
/*
���� ���� ���� N�� ĭ
ù° �ٿ��� ���ڸ� �̾� �ؿ� ĭ ������ ���� ������ �̷��ߵ�
�ִ��� ���� �̾� ���� ������ �����

����Ŭ�� ������� Ž��
*/
vector<int> v;
int N;
int visit[102] = { 0 };

vector<int> ans_list;
void DFS(int stIdx,int cIdx) {

	if (visit[cIdx]) {
		if (stIdx == cIdx)
			ans_list.push_back(stIdx);
	}
	else {
		visit[cIdx] = 1;
		DFS(stIdx, v[cIdx]);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++) {
		DFS(i, i);
		memset(visit, 0, sizeof(visit));
	}
	cout << ans_list.size() << '\n';
	for (int i = 0; i < ans_list.size(); i++) {
		cout << ans_list[i] << '\n';
	}
	return 0;
}