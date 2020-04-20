#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[1000001][2];
bool visit[1000001];
vector<int> edge[1000001];
vector<int> child[1000001];
int N;

void getchild(int now) {
	visit[now] = 1;
	for (int i = 0; i < edge[now].size(); i++) {
		int next = edge[now][i];
		if (!visit[next]) {
			child[now].push_back(next);
			getchild(next);
		}
	}
}
int solve(int now,bool c) {
	if (dp[now][c] != 0)
		return dp[now][c];
	if (child[now].size() == 0)
		return dp[now][c] = c;
	if (c) {
		int ans = 0;
		for (int i = 0; i < child[now].size(); i++) {
			int next = child[now][i];
			ans += min(solve(next, false), solve(next, true));
		}
		return dp[now][c] = ans + 1;
	}
	else {
		int ans = 0;
		for (int i = 0; i < child[now].size(); i++) {
			int next = child[now][i];
			ans += solve(next, true);
		}
		return dp[now][c] = ans;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	getchild(1);
	cout << min(solve(1, false), solve(1, true));
	return 0;
}