#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> score(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < results.size(); i++)
	{
		score[results[i][0]][results[i][1]]++;
		score[results[i][1]][results[i][0]]--;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (score[i][k] == 0)
				continue;

			for (int j = 1; j <= n; j++) {
				if (score[i][k] == score[k][j]) {
					score[i][j] = score[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if ((score[i][j] != 0) && (i != j))
				sum++;
		}
		if (sum == n - 1)
			answer++;
	}

	return answer;
}