#include<iostream>
#include<string>
#include<stack>
using namespace std;

int solve(string s) {
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			if (s[i + 1] == ')') {
				ans += st.size();
				i = i + 1;
			}
			else {
				ans += 1;
				st.push(i);
			}
		}
		else if(s[i] ==')') {
			st.pop();
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		cout<<'#'<<tc<<' ' << solve(s) << '\n';
	}
	return 0;
}