#include <string>
#include <vector>
#include<queue>
#include<functional>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, less<int>> maxpq;
	priority_queue<int, vector<int>, greater<int>> minpq;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			string s = "";
			for (int j = 2; j < operations[i].length(); j++) {
				s += operations[i][j];
			}
			int num = stoi(s);
			maxpq.push(num);
			minpq.push(num);
		}
		else {
			if (operations[i][2] == '1') {
				if (!maxpq.empty()) {
					maxpq.pop();
				}
			}
			else {
				if (!minpq.empty()) {
					minpq.pop();
				}
			}
			if (minpq.empty() || maxpq.empty()) {
				while (!maxpq.empty()) {
					maxpq.pop();
				}
				while (!minpq.empty()) {
					minpq.pop();
				}
			}
			if (!minpq.empty() && !maxpq.empty()) {
				if (minpq.top() > maxpq.top()) {
					while (!maxpq.empty()) {
						maxpq.pop();
					}
					while (!minpq.empty()) {
						minpq.pop();
					}
				}
			}
		}
	}
	if (maxpq.size() == 0 || minpq.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		if (maxpq.size() == 1) {
			answer.push_back(maxpq.top());
			answer.push_back(maxpq.top());
		}
		else if (minpq.size() == 1) {
			answer.push_back(minpq.top());
			answer.push_back(minpq.top());
		}
		else if (minpq.size() == 1 && maxpq.size() == 1) {
			answer.push_back(maxpq.top());
			answer.push_back(minpq.top());
		}
		else {
			answer.push_back(maxpq.top());
			answer.push_back(minpq.top());
		}
	}
	return answer;
}