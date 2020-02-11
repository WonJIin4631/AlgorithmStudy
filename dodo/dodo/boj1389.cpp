#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
인접리스트로 친구에대한 정보저장
1~N까지 친구관계 BFS계산
1~N까지 베이컨거리가 제일 작은 걸 저장
*/
vector<int> list[102];
int ans = 987654321;
int N, M;
int dist[102][102] = { 0 };
void BFS(int idx) {
	queue<pair<int,int>> q;
	for (int i = 0; i < list[idx].size(); i++) {
		q.push(make_pair(list[idx][i], 1));
		dist[idx][list[idx][i]] = 1;
	}
	while (!q.empty()){
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();
		for (int i = 0; i < list[cur].size(); i++) {
			if (idx != list[cur][i]) {
				if (dist[idx][list[cur][i]] == 0) {
					dist[idx][list[cur][i]] = d + 1;
					q.push(make_pair(list[cur][i], d + 1));
				}
			}
		}

	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int fr1, fr2;
		cin >> fr1 >> fr2;
		list[fr1].push_back(fr2);
		list[fr2].push_back(fr1);
	}
	int sumVal = 987654321;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		BFS(i);
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += dist[i][j];
		}
		if (sum < sumVal) {
			sumVal = sum;
			idx = i;
		}
	}
	cout << idx << '\n';
	return 0;
}