#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}
typedef pair<int, int> pii;

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	//요청시간, 수행길이 순서로 정렬
	sort(jobs.begin(), jobs.end());
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int idx = 1;
	pq.push(make_pair(jobs[0][1], jobs[0][0]));// 수행시간, 요청시간,
	int time = jobs[0][0];
	int outIdx = 0;
	while (true) {
		time += pq.top().first;
		answer += time - pq.top().second;
		pq.pop();
		//나간 요청개수 
		outIdx++;
		// 다나가면 종료
		if (outIdx == jobs.size())
			break;
		//범위내에 요청될게 있는지 확인
		bool flag = true;
		if (idx < jobs.size()) {
			for (int i = idx; i < jobs.size(); i++) {
				if (jobs[i][0] <= time) {
					pq.push(make_pair(jobs[i][1], jobs[i][0]));
					idx = i + 1;
					flag = false;
				}
				else
					break;
			}
			// 요청되는게 하나도 없고 현재 큐에 남아잇는것도 없으면 다음 요청수행
			if (flag&&pq.size() == 0) {
				pq.push(make_pair(jobs[idx][1], jobs[idx][0]));
				time = jobs[idx][0];
				idx++;
			}
		}

	}
	answer = answer / jobs.size();
	return answer;
}