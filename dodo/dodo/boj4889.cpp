#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<char> st;
	int T = 1;
	string s;
	while (true) {
		cin >> s;
		if (s[0] == '-')
			break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '{') {
				st.push(s[i]);
			}
			else {
				if (!st.empty()) {
					if (st.top() == '{')
						st.pop();
					else
						st.push(s[i]);
				}
				else {
					st.push(s[i]);
				}
			}
		}
		int ans = 0;
		if (st.empty()) {
			cout << T << ". " << ans << '\n';
		}
		else {
			while (!st.empty()) {
				char cur = st.top();
				st.pop();
				char ne = st.top();
				st.pop();
				if (cur == ne) {
					ans += 1;
				}
				else {
					ans += 2;
				}
			}
			cout << T << ". " << ans << '\n';
		}
		T++;
		s.clear();
	}
	return 0;
}