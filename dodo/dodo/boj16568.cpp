#include<iostream>
#include<algorithm>
using namespace std;
/*
3���� �ൿ�� �Ҽ��ִ�.
1.��ٸ���
2. a�� ������ ����(�ּ� a��������)
3. b�� ������ ���� (�ּ� b�� ������)

1�ʸ��� �� �ջ���� ��ȥ�� �ް� ���� ����.

dp�� Ǭ��
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
