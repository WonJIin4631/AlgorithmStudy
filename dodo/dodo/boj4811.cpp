#include<iostream>
using namespace std;
/*
���� N�� ����� �ִ� ���� �ִ�.
������ ���������� �ݰ� �ϼ��� �ְ� �Ѱ� �ϼ��� �ִ�. ���� �Ѱ��̸� �ݰ��� �԰� �ٽ� ���� �д�.
���̿� �������� ���� ���� W,�������� ���� ���� H ���� ���ڿ� ������.

1000���� �׽�Ʈ ���̽��� �־����� 1~30�������� ����� ���� �̸� ���صд�.
�׸��� �Է¿� �´� ���� ����Ѵ�.
��� �˾��� 30�������� ��츦 ���Ѵ�. �˾� �ݰ��� �Ѱ��� ������ �迭�� ���� ���ǿ� �°� ��� ����
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