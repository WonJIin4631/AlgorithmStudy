#include<iostream>
using namespace std;
/*
약이 N개 담겨져 있는 병이 있다.
병에서 약을꺼낸다 반개 일수도 있고 한개 일수도 있다. 만약 한개이면 반개를 먹고 다시 병에 둔다.
종이에 한조각을 꺼낸 날은 W,반조각을 꺼낸 날은 H 적에 문자에 보낸다.

1000개의 테스트 케이스가 주어진다 1~30개까지의 경우의 수를 미리 구해둔다.
그리고 입력에 맞는 답을 출력한다.
재귀 알약이 30개까지인 경우를 구한다. 알약 반개와 한개를 구분할 배열을 선언 조건에 맞게 재귀 돌림
*/
long long dp[31][31] = { 0 };
long long solve( int f, int h) {
	if (dp[f][h])
		return dp[f][h];
	if (f == 0)
		return 1;
	dp[f][h]=solve( f - 1, h + 1);
	if(h>0) {
		dp[f][h]+=solve(f,h - 1);
	}
	return dp[f][h];
}
int main() {
	int N;
	while (true){
		cin >> N;
		if (N == 0)
			break;
		cout << solve(N, 0)<<'\n';
		
	}
	return 0;
}