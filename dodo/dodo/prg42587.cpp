#include <string>
#include <vector>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;
	stack<int> st;
	int arr[11] = { 0 };
	for (int i = 0; i < priorities.size(); i++) {
		q.push(make_pair(priorities[i], i));
		arr[priorities[i]]++;
	}
	for (int i = 1; i <=9; i++) {
		if (arr[i] != 0) {
			st.push(i);
		}
	}
	while (!q.empty()) {
		int curNum = q.front().first;
		int idx = q.front().second;
		q.pop();
		cout << idx << ' ' << curNum << ' ' << answer << '\n';
		cout << st.top() << '\n';
		if (curNum == st.top() && idx == location) {
			break;
		}
		else if (curNum < st.top()) {
			q.push(make_pair(curNum, idx));
		}
		else {
			arr[curNum]--;
			answer++;
			if (arr[curNum] == 0) {
				st.pop();
			}
		}
	}
	return answer;
}