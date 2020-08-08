#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v;
bool visit[9] = { 0 };
void solve(int cnt,vector<int> ans) {
	if (cnt == M) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			ans.push_back(v[i]);
			solve(cnt + 1, ans);
			visit[i] = false;
			ans.pop_back();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> ans;
	solve(0, ans);
	return 0;
}