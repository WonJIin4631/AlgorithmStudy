#include<iostream>
#include<string>
#include<stack>

using namespace std;

string s;
string ans;
stack<char> st;

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && 'Z' >= s[i])
			ans += s[i];
		else {
			if (s[i] == '(')
				st.push(s[i]);
			else if (s[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					ans += st.top();
					st.pop();
				}
				st.pop();
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					ans += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					ans += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans << '\n';

	return 0;
}