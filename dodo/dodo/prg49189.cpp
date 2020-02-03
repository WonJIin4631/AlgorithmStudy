#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;


int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<vector<int>> conList;
	vector<int> visit(n + 1, 0);
	conList.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		conList[edge[i][0]].push_back(edge[i][1]);
		conList[edge[i][1]].push_back(edge[i][0]);
	}
	queue<pair<int, int>> q;
	visit[1] = 1;
	for (int i = 0; i < conList[1].size(); i++) {
		q.push(make_pair(1, conList[1][i]));
	}
	int maxDist = 1;
	while (!q.empty()) {
		int cur = q.front().second;
		int dist = q.front().first;
		cout << cur << ' ' << dist << '\n';
		q.pop();
		if (visit[cur] == 1)
			continue;
		visit[cur] = 1;
		if (dist > maxDist) {
			maxDist = dist;
			answer = 1;
		}
		else if (dist == maxDist) {
			answer++;
		}
		for (int i = 0; i < conList[cur].size(); i++) {
			if (visit[conList[cur][i]] == 0) {
				cout << conList[cur][i] << '\n';
				q.push(make_pair(dist + 1, conList[cur][i]));
			}
		}
	}

	return answer;
}