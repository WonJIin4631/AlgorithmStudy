#include<iostream>
#include<stack>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

string input;
string tt;
set<string> Set;
int check[202];
bool visit[202];
int ghCnt = 0;
void solve(int idx) {
	if (idx == input.length()) {
		Set.insert(tt);
		return;
	}
	if (input[idx] == '(') {
		visit[check[idx]] = true;
		solve(idx + 1);
		visit[check[idx]] = false;
	}
	if (input[idx] == ')'&&visit[idx]) {
		solve(idx + 1);
	}
	else {
		tt += input[idx];
		solve(idx + 1);
		tt.resize(tt.size() - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> input;
	stack<int> st;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			st.push(i);
		}
		else if (input[i] == ')') {
			int temp = st.top();
			st.pop();
			check[temp] = i;
			check[i] = temp;
			ghCnt++;
		}
	}
	solve(0);
	Set.erase(input);
	set<string> ::iterator iter;
	for (iter = Set.begin(); iter != Set.end(); iter++) {
		cout << (*iter) << '\n';
	}
	return 0;
}