#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
/*
세로 두줄 가로 N개 칸
첫째 줄에서 숫자를 뽑아 밑에 칸 정수가 같은 집합을 이루어야됨
최대한 많이 뽑아 같은 집합을 만들기

사이클이 생기는지 탐색
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