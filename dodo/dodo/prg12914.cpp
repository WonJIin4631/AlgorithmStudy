#include <string>
#include <vector>

using namespace std;
/*
DP��������
1ĭ�̵� 2ĭ�̵� ����
��ó�� 1ĭ�̵��ϴ°��� 1�� 2ĭ���� �̵�->1ĭ2�� 2ĭ 1�� �� 2��
3��° ĭ->3���� ���
4��° ĭ->5���� ���
5��° ĭ->8���� ���
��ȭ��
i��° ĭ -> i-1ĭ ��� + i-2ĭ ���

���⿡ 1234567�� ���� ������ ���� ����
�Ź� ����Ҷ����� 1234567�� ���������� ����
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