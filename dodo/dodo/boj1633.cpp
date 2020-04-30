#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int black[1002];
int white[1002];
int dp[1002][16][16];
int main() {
	int idx = 0;
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		black[idx] = a;
		white[idx++] = b;
	}
	/*
	dp[?][0][0] 둘다 안고른 경우
	dp[?][0][1] 블랙을 고른 경우
	dp[?][1][0] 화이트를 고른 경우
	dp[A][B][C] A번째 까지 B개와 C개를 뽑는 최고의 값
	*/
	
	for (int i = 0; i < idx; i++) {
		dp[i][0][1] = black[i];
		dp[i][1][0] = white[i];
	}
	for (int i = 1; i < idx; i++) {
		for (int j = 15; j >= 0; j--) {
			for (int k = 15; k >= 0; k--) {
				// 이전idx 최대값과 현재idx 최대값을 비교
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if (j >= 1)
					//흰색팀을 추가했을경우 비교
					dp[i][j][k] = max(dp[i - 1][j - 1][k] + white[i], dp[i][j][k]);
				if (k >= 1)
					//흑색팀을 추가했을경우 비교
					dp[i][j][k] = max(dp[i - 1][j][k - 1] + black[i], dp[i][j][k]);
			}
		}
	}
	printf("%d", dp[idx - 1][15][15]);
	return 0;
}