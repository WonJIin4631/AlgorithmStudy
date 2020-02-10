#include<iostream>
#include<algorithm>
using namespace std;

/*
L개의 칸으로 놓여진 감옥, i번방에는 1명의 죄수가 들어오며 탈옥력을 가지고있다.
간수는 최대 G명 고용가능, 탈옥 위험도를 최소로 하도록 배치, 간수는 인접한 칸을 감시
i번 칸의 탈옥 위험도 Ri는 탈옥력 Ci와 i번 칸을 감시하는 간수가 감시하고 있는 죄수의 수를 곱한 값이다.
탈옥 위험도는 모든칸의 Ri를 더한 값

DFS로 풀기
현재 간수의 수 ,남은 방의 수,현재위치,더한값 
시간초과 -> 조건을 더 세밀하게? -> DP로 풀어야됨


*/
int L, G;
typedef long long ll;

ll arr[8003], sum[8003];
ll dp[803][8003], p[803][8003];

inline ll cost(int i, int j) {
	return (sum[j] - sum[i - 1])*(j - i + 1);
}
void go(int t, ll l, ll r, ll pl, ll pr) {
	if (l > r)
		return;
	int mid = (l + r) >> 1;
	dp[t][mid]= - 1;
	p[t][mid] = -1;
	for (int k = pl; k <= pr; k++) {
		ll tmp = dp[t - 1][k] + cost(k + 1, mid);
		if (dp[t][mid] == -1 || dp[t][mid] > tmp) {
			dp[t][mid] = tmp;
			p[t][mid] = k;
		}
	}
	go(t, l, mid - 1, pl, p[t][mid]);
	go(t, mid + 1, r, p[t][mid], pr);
}
int main() {
	cin>> L >> G;
	for (int i = 1; i <= L; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i <= L; i++) 
		dp[1][i] = cost(1, i), p[1][i] = 0;
	for (int t = 2; t <= G; t++) 
		go(t, 0, L, 0, L);

	cout << dp[G][L]<<'\n';
	return 0;
}