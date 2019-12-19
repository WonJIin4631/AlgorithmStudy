#include<iostream>
#include<vector>
using namespace std;

vector<vector<pair<int, int>>> v;
int N, M;
int INF = 987654321;
int main() {
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v[i].push_back(make_pair(INF, -1));
			if (i == j)
				v[i][j].first = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		if(v[from - 1][to - 1].first > val)
			v[from - 1][to - 1].first = val;
		v[from - 1][to - 1].second = from - 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (v[k][j].first > v[k][i].first + v[i][j].first) {
					v[k][j].first = v[k][i].first + v[i][j].first;
					v[k][j].second = v[i][j].second;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j].second == -1)
				cout << 0 << ' ';
			else
				cout << v[i][j].first << ' ';
		}
		cout << '\n';
	}
}