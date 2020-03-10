#include<iostream>
#include<algorithm>
using namespace std;
/*
K�� ������ ������ �ִ� N���� ���� ������ �������� ������ �Ѵ�

0~�ִ� ������ ���� ��������
�̺�Ž���� �ؼ� ����Ѵ�.
������ ������ ������ �ø��� ������ ������ ���̸� ���δ�.
*/
int K, N;
long long line[10002];
long long ans;
int main() {
	long long left, right, mid;
	left=right = 1;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		right = max(right, line[i]);
	}
	while (true){
		mid = (left + right) / 2;
		if (left > right) {
			ans = mid;
			break;
		}
		long long temp = 0;
		for(int i=0;i<K;i++){
			temp += line[i] / mid;
		}
		if (temp >= N) {
			left = mid+1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}