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
	dp[?][0][0] �Ѵ� �Ȱ� ���
	dp[?][0][1] ���� �� ���
	dp[?][1][0] ȭ��Ʈ�� �� ���
	dp[A][B][C] A��° ���� B���� C���� �̴� �ְ��� ��
	*/
	
	for (int i = 0; i < idx; i++) {
		dp[i][0][1] = black[i];
		dp[i][1][0] = white[i];
	}
	for (int i = 1; i < idx; i++) {
		for (int j = 15; j >= 0; j--) {
			for (int k = 15; k >= 0; k--) {
				// ����idx �ִ밪�� ����idx �ִ밪�� ��
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if (j >= 1)
					//������� �߰�������� ��
					dp[i][j][k] = max(dp[i - 1][j - 1][k] + white[i], dp[i][j][k]);
				if (k >= 1)
					//������� �߰�������� ��
					dp[i][j][k] = max(dp[i - 1][j][k - 1] + black[i], dp[i][j][k]);
			}
		}
	}
	printf("%d", dp[idx - 1][15][15]);
	return 0;
}