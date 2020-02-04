#include <string>
#include <vector>

using namespace std;
/*
DP문제같음
1칸이동 2칸이동 가능
맨처음 1칸이동하는경우는 1개 2칸으로 이동->1칸2번 2칸 1번 총 2개
3번째 칸->3가지 방법
4번째 칸->5가지 방법
5번째 칸->8가지 방법
점화식
i번째 칸 -> i-1칸 방법 + i-2칸 방법

여기에 1234567를 나눈 나머지 값을 리턴
매번 계산할때마다 1234567의 나머지값을 대입
*/
long long solution(int n) {
	long long answer = 0;
	long long dp[2002];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;
	}
	answer = dp[n];
	return answer;
}