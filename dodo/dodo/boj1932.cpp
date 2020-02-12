#include<iostream>
#include<algorithm>
using namespace std;

/*
���������� �ǾƷ������� ���� ���ϸ鼭 ������ �� �Ʒ��������� �տ��� �ִ밪�� ���
�Ʒ��밢��, �Ʒ��밢�� �������� ���Ҽ�����

DP��� 
������ ������ �ִ밪���� ��� ���ذ�
���� ���� ������ ���� ���Ͽ� ū���� ����

*/
int map[501][501];
int dp[501][501] = { 0 };
int N;
int ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = map[0][0];
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], map[i + 1][j] + dp[i][j]);
			dp[i + 1][j+1] = max(dp[i + 1][j+1], map[i + 1][j+1] + dp[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[N - 1][i]);
	}
	cout << ans << '\n';
	return 0;
}