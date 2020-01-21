#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321;
int list[10002];
vector < vector<pair<int, int>>> v;
int N;

int main() {
	cin >> N;
	v.resize(N+1);
	for (int i = 1; i <= N; i++) {
		int cost, K;
		cin >> cost >> K;
		if (K == 0)
			v[0].push_back(make_pair(cost, i));
		for (int j = 0; j < K; j++) {
			int from;
			cin >> from;
			v[from].push_back(make_pair(cost, i));
		}
	}
	for (int i = 1; i <= N; i++) {
		list[i] = INF;
	}
	for (int i = 0; i < v[0].size(); i++) {
		list[v[0][i].second] = v[0][i].first;
		dfs(v[0][i].second);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout<<i<<":  " << v[i][j].second << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		cout << list[i] << '\n';
	}
	return 0;
}