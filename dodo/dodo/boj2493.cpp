#include<iostream>
#include<stack>
using namespace std;

typedef pair<int, int> pii;
int N;
stack<pii> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++){
		int num;
		cin >> num;
		while (!st.empty()) {
			if (st.top().second >= num) {
				cout << st.top().first << ' ';
				break;
			}
			st.pop();
		}
		if (st.empty())
			cout << '0' << ' ';
		st.push(make_pair(i, num));
	}
	return 0;
}