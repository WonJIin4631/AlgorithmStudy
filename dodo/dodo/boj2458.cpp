#include<iostream>
using namespace std;
int map[501][501];
int N, M;
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][k] && map[k][j])
					map[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			if (map[i][j] == 0 && map[j][i] == 0)
				cnt++;
		}
		if (cnt == 0)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}