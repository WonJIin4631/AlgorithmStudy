#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int visit[21] = { 0 };
int maxCnt;
int maxLen;
int ans = 987654321;
string s;
vector<int> v;
void dfs(int idx, int move, int cnt) {
	cout << idx << ' ' << move << ' ' << cnt << '\n';
	if (cnt == maxCnt) {
		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (visit[i] == 0) {
				flag = false;
			}
		}
		if(flag)
			ans = min(ans, move);
		return;
	}
	for (int i = 0; i < s.length(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			int fromL = abs(idx - i);
			int fromR = abs(idx - maxLen);
			int nextMove = min(fromL , fromR );
			if (idx == 0 && i == s.length() - 1) {
				nextMove = 1;
			}
			dfs(i, move + min(s[i] - 'A', 'Z' - s[i] + 1) + nextMove, cnt + 1);
			visit[i] = 0;
		}
	}
}
int solution(string name) {
	int answer = 0;
	s = name;
	maxCnt=maxLen = name.length();
	visit[0] = 1;
	int cnt = 0;
	for (int i = 0; i < maxLen; i++) {
		if (s[i] == 'A') {
			visit[i] = 1;
			cnt++;
		}
	}
	maxCnt -= cnt;
	if(s[0]=='A')
		dfs(0, min(s[0] - 'A', 'Z' - s[0] + 1), 0);
	else 
		dfs(0, min(s[0] - 'A', 'Z' - s[0] + 1), 1);
	answer = ans;
	return answer;
}