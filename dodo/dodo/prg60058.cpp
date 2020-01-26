#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

bool check(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			cnt++;
		else if (s[i] == ')')
			cnt--;
		if (cnt < 0)
			return false;
	}
	return true;
}
string solution(string p) {
	vector<int> v;
	string s;
	stack<int> st;
	string answer = "";
	if (check) {
		answer = p;
	}
	else {
		int open = 0;
		int close = 0;
		bool reverse = false;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == '(')
				open++;
			else
				close++;
			if (open == close) {
				if (reverse) {
					if (p[i] == '(') {
						answer += ')';
						reverse = false;
					}
				}
				else {
					if (p[i] == ')')
						answer += ')';
				}

			}
			else if (open > close) {
				if (p[i] == '(')
					answer += '(';
				else
					answer += ')';
			}
			else if (open < close) {
				reverse = true;
				if (p[i] == ')')
					answer += '(';
				else
					answer += ')';
			}
		}
	}
	return answer;
}