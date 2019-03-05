#include<iostream>
#include<string>
#include<stack>
using namespace std;


int N;
int cnt = 0;
int main() {
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<char> st, st2;
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			st.push(s[j]);
		}
		while (!st.empty()) {
			if (st2.empty()) {
				st2.push(st.top());
				st.pop();
			}
			else if(st2.top() == st.top()) {
				st2.pop();
				st.pop();
			}
			else {
				st2.push(st.top());
				st.pop();
			}
		}
		if (st2.empty())
			cnt++;
	}
	cout << cnt << "\n";
}