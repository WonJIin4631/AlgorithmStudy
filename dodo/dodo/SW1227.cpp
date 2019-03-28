#include <iostream>
#include <string>
using namespace std;

int dfs(int n, int m, int map[][100], int visited[][100]) {
	visited[n][m] = 1;

	if (map[n][m] == 3) {
		return 1;
	}
	else {
		if ((map[n - 1][m] == 0 || map[n - 1][m] == 3) && visited[n - 1][m] == 0)
			dfs(n - 1, m, map, visited);
		if ((map[n + 1][m] == 0 || map[n + 1][m] == 3) && visited[n + 1][m] == 0)
			dfs(n + 1, m, map, visited);
		if ((map[n][m - 1] == 0 || map[n][m - 1] == 3) && visited[n][m - 1] == 0)
			dfs(n, m - 1, map, visited);
		if ((map[n][m + 1] == 0 || map[n][m + 1] == 3) && visited[n][m + 1] == 0)
			dfs(n, m + 1, map, visited);

	}

	return 0;
}

int main() {
	for (int testcase = 1; testcase <= 10; testcase++) {
		int t, answer = 0;
		int map[100][100];
		string num;
		int visited[100][100] = { 0, };

		cin >> t;

		for (int i = 0; i < 100; i++) {
			cin >> num;
			for (int j = 0; j < 100; j++) {
				map[i][j] = num[j] - '0';
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (map[i][j] == 2)
					dfs(i, j, map, visited);
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (map[i][j] == 3)
					answer = visited[i][j];
			}
		}

		cout << "#" << t << " " << answer << endl;
	}
}