#include<iostream>
#include<algorithm>
using namespace std;
/*
3가지 행동을 할수있다.
1.기다리기
2. a명 앞으로 가기(최소 a명있을때)
3. b명 앞으로 가기 (최소 b명 있을때)

1초마다 맨 앞사람은 영혼을 받고 집에 간다.

dp로 푼다
*/
int main() {
	int dp[1000002] = { 0 };
	int N, a, b;

	cin >> N >> a >> b;

	for (int i = 1; i <= N; i++)
		dp[i] = 987654321;

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i - a - 1 >= 0)
			dp[i] = min(dp[i], dp[i - a - 1] + 1);
		if (i - b - 1 >= 0)
			dp[i] = min(dp[i], dp[i - b - 1] + 1);
	}
	cout << dp[N];
}
