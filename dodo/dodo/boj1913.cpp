#include<iostream>
using namespace std;

int N, M;
int ans[2];
int map[1000][1000];
void solve(int n, int r) {
	for (int i = 0 + r; i < N - r; i++) {
		if (n == M) {
			ans[0] = i;
			ans[1] = r;
		}
		map[i][r] = n--;
		if (n == 0)
			return;
	}
	for (int i = r + 1; i < N - r; i++) {
		if (n == M) {
			ans[0] = N - 1 - r;
			ans[1] = i;
		}
		map[N - 1 - r][i] = n--;
		if (n == 0)
			return;
	}
	for (int i = N - 1 - (r + 1); i >= 0 + r; i--) {
		if (n == M) {
			ans[0] = i;
			ans[1] = N - 1 - r;
		}
		map[i][N - 1 - r] = n--;
		if (n == 0)
			return;
	}
	for (int i = N - 1 - (r + 1); i >= 0 + r + 1; i--) {
		if (n == M) {
			ans[0] = r;
			ans[1] = i;
		}
		map[r][i] = n--;
		if (n == 0)
			return;
	}
	solve(n, r + 1);
}

int main() {
	cin >> N >> M;
	solve(N*N, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans[0] + 1 << ' ' << ans[1] + 1 << '\n';
	return 0;
}