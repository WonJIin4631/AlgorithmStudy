#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int dp[202][202];
int N, M, K;
string ans = "";
int combination(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	else if (dp[n][r] != 0) {
		return dp[n][r];
	}
	else {
		return dp[n][r] = min(combination(n - 1, r - 1) + combination(n - 1, r), (int) 1e9);
	}
}

//n : a의 개수 , m : z의 개수 , k번째
void query(int n, int m, int k) {
	//n+m ==0 끝
	if (n + m == 0) {
		return;
	}
	//n==0 선택할 a가 더 없음 -> z로 채움
	else if (n == 0) {
		ans += "z";
		query(n, m - 1, k);
	}
	//m==0 선택할 z가 없음 -> a로 채움
	else if (m == 0) {
		ans += "a";
		query(n - 1, m, k);
	}
	//a나 z를 선택해야 하는 케이스
	else {
		int aCount = combination(n + m - 1, m);
		if (aCount >= k) {
			ans += "a";
			query(n - 1, m, k);
		}
		else {
			ans += "z";
			query(n, m - 1, k-aCount);
		}
	}	
}
int main() {
	cin >> N >> M >> K;
	if (K > combination(N + M, M)) {
		cout << -1 << '\n';
	}
	else {
		query(N, M, K);
		cout << ans << '\n';
	}
	return 0;
}