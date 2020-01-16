#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int island[101] = { 0 };
	int map[101][101] = { 0 };
	for (int i = 0; i < costs.size(); i++) {
		map[costs[i][0]][costs[i][1]] = costs[i][2];
		map[costs[i][1]][costs[i][0]] = costs[i][2];
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		if (map[0][i] != 0)
			pq.push(make_pair(map[0][i], i));
	}
	island[0] = 1;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (island[cur])
			continue;
		island[cur] = 1;	
		answer += cost;
		for (int i = 0; i < n; i++) {
			if (map[cur][i] != 0) {
				if (island[i] == 0) {
					pq.push(make_pair(map[cur][i], i));
				}
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	cout << map[i][j] << ' ';
	}cout << '\n';
	}*/
	return answer;
}