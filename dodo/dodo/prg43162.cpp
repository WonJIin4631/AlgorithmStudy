#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<string.h>
#include<set>
using namespace std;

int visit[201];

void BFS(int start, int n, vector<vector<int>> computers) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		if (computers[start][i] == 1) {
			if (visit[i] == -1) {
				q.push(make_pair(start, i));
				visit[i] = start;
			}
		}
	}
	while (!q.empty()) {
		int st = q.front().first;
		int to = q.front().second;
		q.pop();
		for (int i = 0; i < n; i++) {
			if (visit[i] == -1) {
				if (computers[to][i] == 1) {
					visit[i] = st;
					q.push(make_pair(start, i));
				}
			}
		}
	}
}
set<int> Set;
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i<n; i++) {
		BFS(i, n, computers);
	}
	for (int i = 0; i < n; i++) {
		if (Set.find(visit[i]) == Set.end()) {
			answer++;
			Set.insert(visit[i]);
		}
	}
	return answer;
}