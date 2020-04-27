#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int N;
int map[21][21];
int check[21];
int ans = 987654321;
void solve(int idx, vector<int> st, vector<int> lt) {
	if (idx == N) {
		
		int stSum = 0;
		for (int i = 0; i < st.size(); i++) {
			for (int j = i + 1; j < st.size(); j++) {
				stSum += (map[st[i]][st[j]] + map[st[j]][st[i]]);
			}
		}
		int ltSum = 0;
		for (int i = 0; i < lt.size(); i++) {
			for (int j = i + 1; j < lt.size(); j++) {
				ltSum += (map[lt[i]][lt[j]] + map[lt[j]][lt[i]]);
			}
		}
		ans = min(ans, abs(stSum - ltSum));
		return;
	}
	if (st.size() < N / 2) {
		st.push_back(idx);
		solve(idx + 1, st, lt);
		st.pop_back();
	}
	if (lt.size() < N / 2) {
		lt.push_back(idx);
		solve(idx + 1, st, lt);
		lt.pop_back();
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	vector<int> link;
	vector<int> start;
	solve(0, start, link);
	cout << ans << '\n';
	return 0;
}