#include <string>
#include <vector>
#include<queue>
#include<functional>
#include<iostream>
using namespace std;


int solution(vector<int> scoville, int K) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int answer = 0;
	bool flag = false;
	int cnt = 1;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	while (!pq.empty()) {
		int curVal = pq.top();
		cout << cnt << '\n';
		pq.pop();
		if (curVal >= K) {
			flag = true;
			break;
		}
		int nextVal;
		if (!pq.empty()) {
			nextVal = pq.top();
			pq.pop();
		}
		int newVal = curVal + (nextVal * 2);

		pq.push(newVal);
		cnt++;
	}
	if (flag)
		answer = cnt;
	else
		answer = -1;
	return answer;
}