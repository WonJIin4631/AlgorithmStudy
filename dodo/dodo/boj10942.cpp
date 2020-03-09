#include<iostream>
#include<cstring>
using namespace std;
/*
�ڿ��� N���� �־��� ������ M�� �Ѵ�.
S��° �� ���� E������ ���� �Ӹ������ �̷���� ����µ� �´��� �ƴ��� �˷��� (�� 1 , ���� 0)

�ڿ��� ������ 1�ΰ͵��� ������ �Ӹ�����̴�
������ 2�� ���� ������ġ S�� S+1�� ��ġ ���� ������ �Ӹ�����̴�.
3�̻��ΰ��� ���� ��ġ�� S+(����-1) ���� ���� ���� ��� dp[s+1][s+j-1]�� �Ӹ�����̸� �Ӹ�����̴�. ���� 2���� ���̿����� �Ӹ������ �ȴ�.
������ ���ؼ� ���� ����ϸ� �ߺ��Ǵ� ����� �־� �ߺ� ����� �ּ�ȭ �ϱ� ���ؼ� DP�� Ȱ���Ͽ� ������ Ǭ��.

*/

int N, M;
int arr[2001];
bool dp[2001][2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> M;
	memset(dp, false, sizeof(dp));
	//���� 1
	for (int i = 1; i <= N; i++) 
		dp[i][i] = true;
	//���� 2
	for (int i = 1; i <= N; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	//���� 3�̻�
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
		}
	}
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
	return 0;
}