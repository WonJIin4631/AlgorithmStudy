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
	//��û�ð�, ������� ������ ����
	sort(jobs.begin(), jobs.end());
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int idx = 1;
	pq.push(make_pair(jobs[0][1], jobs[0][0]));// ����ð�, ��û�ð�,
	int time = jobs[0][0];
	int outIdx = 0;
	while (true) {
		time += pq.top().first;
		answer += time - pq.top().second;
		pq.pop();
		//���� ��û���� 
		outIdx++;
		// �ٳ����� ����
		if (outIdx == jobs.size())
			break;
		//�������� ��û�ɰ� �ִ��� Ȯ��
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
			// ��û�Ǵ°� �ϳ��� ���� ���� ť�� �����մ°͵� ������ ���� ��û����
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