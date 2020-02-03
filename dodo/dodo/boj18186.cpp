#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
/*
N���� ��� ���� i��������  A���� ����� ����

3���� ������� ��鱸��
1�� i�� ���忡�� ����� �ϳ� ���� B��
2�� i�� ����� (i+1)�� ���� ���� ��� �ϳ� ���� (B+C)��
3�� i�� ����� (i+1)�� ����, (i+2)�� ���� ���� ��� �ϳ� ���� (B+2C)
�ּұݾ� ���
DP���� ����
i���� ��������� ���� �ݾ׺��� ���� ������� ��� ����
Ȥ�� BFS?
1�� 2�� 3�� ������� ������

*/


int main() {
	int N, B, C;
	int lamen[100002];
	cin >> N >> B >> C;
	for (int i = 1; i <= N; i++) {
		cin >> lamen[i];
	}
	long long dp[3][1000002] = { 0 };

	for (int i = 0; i < 3; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= N; i++) {
		dp[0][i] = (B*lamen[i]);
		if (i >= 2) {
			int maxCnt = max(lamen[i - 1], lamen[i]);
			dp[1][i] = (B + C)*maxCnt;
		}
		if (i >= 3) {
			int maxCnt = max(lamen[i - 1], lamen[i]);
			maxCnt = max(maxCnt, lamen[i-2]);
			dp[2][i] =  (B + 2*C)*maxCnt;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << '\n';
		long long temp = min(dp[0][i], dp[1][i]);
		temp = min(temp, dp[2][i]);
		ans += temp;
	}
	cout << ans << '\n';
	return 0;
}