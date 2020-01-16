#include<iostream>
#include<memory.h>
using namespace std;

#define INF 987654321 
int N, M;

int map[502][502] = { 0 };
int visit[502] = { 0 };

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int  ans = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = INF;
			}
		}
		for (int i = 0; i < M; i++) {
			int st1, st2;
			cin >> st1 >> st2;
			map[st1][st2] = 1;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					if (map[j][k] > map[j][i] + map[i][k])
						map[j][k] = map[j][i] + map[i][k];
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] != INF) {
					visit[i]++;
					visit[j]++;
					if (visit[i] == N - 1)
						ans++;
					if (visit[j] == N - 1)
						ans++;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}