#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N;
int dp[2002][2002];
int A[2002];
int B[2002];
int solve(int l, int r) {
	//ī�� ���� ���� ����������
	if (l == N || r == N)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	//���� ���ڰ� ������ ���ں��� Ŭ��� -> ������ ī�� �������� ��
	if (A[l] > B[r]) {
		dp[l][r] = max(dp[l][r], solve(l, r + 1) + B[r]);
	}
	//������ ī�尡 ũ�� ���� ī�� �����ų� �Ѵ� �������
	else {
		dp[l][r] = max(solve(l + 1, r), solve(l + 1, r + 1));
	}
	return dp[l][r];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	cout << solve(0, 0)<<'\n';
	return 0;
}