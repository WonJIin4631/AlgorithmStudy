#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool visit[11] = { 0 };
int N;
int map[11][11];

int list[11];
int ans = 987654321;

int val = 0;
vector<int> v;
void solve(int prev) {
	if (v.size() == N) {
		if (map[v.at(N - 1)][v.at(0)] != 0) {
			for (int i = 0; i < N - 1; i++) {
				val += map[v.at(i)][v.at(i + 1)];
			}
			val += map[v.at(N - 1)][v.at(0)];
			ans = min(ans, val);
			val = 0;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visit[i] && (map[prev][i] != 0)) {
				visit[i] = 1;
				v.push_back(i);
				solve(i);
				v.pop_back();
				visit[i] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		v.push_back(i);
		solve(i);
		v.pop_back();
		visit[i] = 0;
	}
	cout << ans<<'\n';
	return 0;
}