#include <string>
#include <vector>
#include<iostream>
#include <set>
using namespace std;

/*
유일성 최소성을 만족하는 후보키
후보키의 최대개수

*/

set<string> Set;
int ans = 0;
int col;
int visit[9] = { 0 };
void solve(int idx, vector<int>& v, vector<vector<string>>& relation) {
	if (v.size() >= 1 && v.size() <= col) {
		for (int j = 0; j < v.size(); j++) {
			cout << v[j] << ' ';
		}
		cout << '\n';
		bool flag = true;
		for (int i = 0; i < relation.size(); i++) {
			string s = "";
			for (int j = 0; j < v.size(); j++) {
				s += relation[i][v[j]];
			}
			cout << s << '\n';
			if (Set.find(s) == Set.end()) {
				Set.insert(s);
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (ans < v.size())
				ans = v.size();
			cout << "END\n";
			return;
		}
	}
	for (int i = idx; i < col; i++) {
		if (visit[i] == 0) {
			v.push_back(i);
			visit[i] = 1;
			solve(i, v, relation);
			visit[i] = 0;
			v.pop_back();
		}
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	col = relation[0].size();
	vector<int> v;
	solve(0, v, relation);
	return ans;
}