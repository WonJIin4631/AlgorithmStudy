#include<iostream>
#include<algorithm>
using namespace std;
/*
높이는 1~n n개의 막대로 구성,왼쪽에서 보이는 막대 개수 l와 오른쪽에서 보이는 막대 개수 r
높이가 중복되는 막대는 없다.

1,N과 N,1은 1가지 경우 밖에 없다.
1,1이 경우는 1만가능
점화식이 생기는 것을 확인
dp[n][l][r]=(높이가 1인 막대의 위치가 제일 왼쪽인 경우)+ (높이가 1인 막대의 위치가 제일 오른쪽인경우)+(n-2)*(높이가 1인 막대의 위치가 2~n-1위치인 경우)
*/
int main() {
	long long dp[21][21][21] = { 0 };
	dp[1][1][1] = 1;
	for (int n = 2; n <= 20; n++) {
		for (int l = 1; l <= 20; l++) {
			for (int r = 1; r <= 20; r++) {
				dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + (n - 2)*dp[n - 1][l][r];
			}
		}
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, l, r;
		cin >> n >> l >> r;
		cout << dp[n][l][r] << '\n';
	}
	return 0;
}