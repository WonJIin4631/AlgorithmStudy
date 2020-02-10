#include<iostream>
#include<algorithm>
using namespace std;

/*
L���� ĭ���� ������ ����, i���濡�� 1���� �˼��� ������ Ż������ �������ִ�.
������ �ִ� G�� ��밡��, Ż�� ���赵�� �ּҷ� �ϵ��� ��ġ, ������ ������ ĭ�� ����
i�� ĭ�� Ż�� ���赵 Ri�� Ż���� Ci�� i�� ĭ�� �����ϴ� ������ �����ϰ� �ִ� �˼��� ���� ���� ���̴�.
Ż�� ���赵�� ���ĭ�� Ri�� ���� ��

DFS�� Ǯ��
���� ������ �� ,���� ���� ��,������ġ,���Ѱ� 
�ð��ʰ� -> ������ �� �����ϰ�? -> DP�� Ǯ��ߵ�


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