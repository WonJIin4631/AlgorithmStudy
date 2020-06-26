#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N;
int dp[2002][2002];
int A[2002];
int B[2002];
int solve(int l, int r) {
	//카드 더미 남아 있지않으면
	if (l == N || r == N)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	//왼쪽 숫자가 오른쪽 숫자보다 클경우 -> 오른쪽 카드 버릴경우랄 비교
	if (A[l] > B[r]) {
		dp[l][r] = max(dp[l][r], solve(l, r + 1) + B[r]);
	}
	//오른쪽 카드가 크면 왼쪽 카드 버리거나 둘다 버릴경우
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