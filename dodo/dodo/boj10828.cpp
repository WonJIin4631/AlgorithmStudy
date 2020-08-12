#include<iostream>
#include<string>
#include<stack>
using namespace std;
int N;
stack<int> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			st.push(n);
		}
		else if (s == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else {
				cout << -1 << '\n';
			}

		}
		else if (s == "size") {
			cout << st.size() << '\n';
		}
		else if (s == "empty") {
			if (!st.empty()) {
				cout << 0 << '\n';
			}
			else
				cout << 1 << '\n';
		}
		else {
			if (!st.empty()) {
				cout << st.top() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}