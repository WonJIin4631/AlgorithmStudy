#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string p) {
	string answer = "";
	int l = 0, r = 0; 
	bool check = false; 
	if (p.length() == 0) return "";
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') 
			l++;
		if (p[i] == ')') 
			r++;
		if (r > l) 
			check = true;
		if (l== r) {
			if (check) { 
				answer += '(';
				answer += solution(p.substr(i + 1, p.length() - i - 1));
				answer += ')';
				for (int j = 1; j < i; j++) {
					if (p[j] == ')') 
						answer += '(';
					if (p[j] == '(') 
						answer += ')';
				}
				return answer;
			}
			else { 
				answer += p.substr(0, i + 1);
				answer += solution(p.substr(i + 1, p.length() - i - 1));
				return answer;
			}
		}
	}
}