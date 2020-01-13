#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	long long dp[101][101] = { 0 };
	dp[0][0] = 1;
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
	}
	int dx[] = { 1,0 };
	int dy[] = { 0,1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] == -1)
				continue;
			for (int dir = 0; dir < 2; dir++) {
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;
				if (dp[ny][nx] != -1) {
					dp[ny][nx] += dp[i][j] % 1000000007;
				}
			}
		}
	}
	answer = dp[n - 1][m - 1];
	return answer;
}