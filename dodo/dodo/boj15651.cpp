#include<iostream>
#include<vector>
using namespace std;

int N, M;
int visit[9];
vector<int> v;

void solve(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i =1; i <= N; i++) {
		v.push_back(i);
		solve(cnt + 1);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;
	solve(0);
	return 0;
}