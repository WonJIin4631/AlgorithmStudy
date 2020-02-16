#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
/*
1이 나온 위치부터 bfs 탐색 
bfs 탐색하면서 단지의 크기를 확인
오름차순으로 정렬


*/
typedef pair<int, int> pii;
int N;
string map[26];
int visit[26][26];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int danji_num(int x, int y) {
	queue<pii> q;
	q.push(pii(y, x));
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
				if (visit[ny][nx] == 0) {
					if (map[ny][nx] == '1') {
						visit[ny][nx] = 1;
						q.push(pii(ny, nx));
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	vector<int> list;
	int n = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				if (visit[i][j] == 0) {
					visit[i][j] = 1;
					int danjisu = danji_num(j, i);
					list.push_back(danjisu);
				}
			}
		}
	}
	sort(list.begin(), list.end());
	cout << list.size() << '\n';
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << '\n';
	}
	return 0;
}