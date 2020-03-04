#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
/*
��ƼĿ�� ���� �ִ������� ȹ���ؾߵ�, ��ƼĿ�� ���� �����¿�� �̿����� ����

������,�����,�ǳʶٱ� 3������ ���డ��

*/
int map[2][100002] = { 0 };
int dp[2][100002] = { 0 };//0�� ������, 1 ����� 2 �ǳʶٱ�
int T, N;

void solve() {
	for (int i = 0; i< N; i++) {
		//������ ����
		dp[1][i+1] = max(dp[0][i] + map[1][i+1], dp[1][i+1]);
		//����� 
		dp[0][i+1]=max(dp[1][i] + map[0][i+1], dp[0][i+1]);
		//�ǳʶٱ�
		if (i+2<=N) {
			//2ĭ�� ������ 
			dp[0][i+2] = max(dp[1][i] + map[0][i+2], dp[0][i] + map[0][i+2]);
			dp[1][i+2] = max(dp[1][i] + map[1][i+2], dp[0][i] + map[1][i+2]);
		}
	}
}
int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		solve();
		cout << max(dp[0][N], dp[1][N])<<'\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}