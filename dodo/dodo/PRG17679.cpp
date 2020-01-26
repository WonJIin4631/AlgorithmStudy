#include <string>
#include <vector>
#include<queue>
#include<iostream>	
using namespace std;

int dx[] = { 0,1,0,1 };
int dy[] = { 0,0,1,1 };

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag = false;
	vector<pair<int, int>> list;
	int map[31][31] = { 0 };
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = board[i][j] - 'A';
		}
	}
	while (true) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout<<map[i][j]<<' ';
			}
			cout << '\n';
		}
		flag = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != -1) {
					int temp = map[i][j];
					bool check = true;
					for (int k = 0; k < 4; k++) {
						if (temp != map[i + dy[k]][j + dx[k]]) {
							check = false;
							break;
						}
					}
					if (check) {
						list.push_back(make_pair(i, j));
						flag = true;
					}
				}
			}
		}
		if (!flag)
			break;
		for (int i = 0; i < list.size(); i++) {
			int x = list[i].second;
			int y = list[i].first;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				map[ny][nx] = -1;
			}
		}
		queue<int> q;
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (map[j][i] != -1)
					q.push(map[j][i]);
			}
			int sz = q.size();
			for (int j = m - 1; j > m - 1 - sz; j--) {
				map[j][i] = q.front();
				q.pop();
			}
			for (int j = m - 1 - sz; j >= 0; j--) {
				map[j][i] = -1;
			}
		}
		list.clear();
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == -1)
				answer++;
		}
	}
	return answer;
}