#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int numList[9];
int ansList[9];
void DFS(int idx,int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ansList[i]<<' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < N; i++) {
		ansList[cnt] = numList[i];
		DFS(i,cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL)''
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> numList[i];
	}
	sort(numList, numList + N);
	DFS(0, 0);
	return 0;
}