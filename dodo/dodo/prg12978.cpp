#include<iostream>
#include<vector>
#include<functional>
#include<queue>
using namespace std;

#define INF 987654321
/*
N개의 마을 1~N ,양방향 통행 1번마을에서 각마을 음식주문 K시간 이하로 배달이 가능한 마을 주문만 받음
a,b,c a,b 마을 C는거리

우선순위 큐로 1번 마을부터 탐색
*/

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
	return a.first < b.first;
}
int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	int map[52][52] = { 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < road.size(); i++) {
		if (map[road[i][0]][road[i][1]] > road[i][2]) {
			map[road[i][0]][road[i][1]] = road[i][2];
			map[road[i][1]][road[i][0]] = road[i][2];
		}
	}
	int visit[52] = { 0 };
	int dist[52] = { 0 };

	priority_queue < pii, vector<pii>, greater<pii>>pq;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		if (map[1][i] != INF) {
			pq.push(make_pair(map[1][i], i));
		}
	}
	visit[1] = 1;
	dist[1] = 0;
	while (!pq.empty()) {
		int curP = pq.top().second;
		int val = pq.top().first;
		pq.pop();

		if (visit[curP])
			continue;
		visit[curP] = 1;
		if (dist[curP] >= val)
			dist[curP] = val;

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0) {
				if (map[curP][i] != INF) {
					if (curP != i) {
						pq.push(make_pair(val + map[curP][i], i));
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K)
			answer++;
	}
	return answer;
}