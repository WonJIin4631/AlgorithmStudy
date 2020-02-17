#include<iostream>
using namespace std;
/*
������ �ִ� �ּҰ��� ���̴� 0~9999���� ���ü� �ִ�
�������� ���� �̺�Ž������ �������� ������ ������ ���ϸ鼭 Ž��
������ ���� ���������� �������̰� ����
������ ���� ���������� �������̰� ����

*/
int N, M;
int list[5002];
//������� ������������ Ȯ��
int check(int n) {
	int min_n = list[0];
	int max_n = list[0];
	int res = 1;
	for (int i = 1; i < N; i++) {
		//�ּҰ� Ȯ��
		if (list[i] < min_n)
			min_n = list[i];
		//�ִ밪 Ȯ��
		if (list[i] > max_n)
			max_n = list[i];
		//�ִ� �ּҰ��� ���̰� ���� ���� ���̰����� ũ�� ����¥��
		if (max_n - min_n > n)
			min_n = max_n = list[i], res++;
	}
	//������� ©���� ������ ���� ��ȯ
	return res;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int l = 0;
	int r = 9999;
	//�ִ밪 �������� ������ ���� 
	//�̺�Ž������ ������ ������ ����
	int c;
	while (l <= r) {
		//
		c = (l + r) / 2;
		//M���� ������ ���� ������ ������
		if (check(c) > M) {
			l = c + 1;
		}
		//M���� ������ ���� ������ ������
		else {
			r = c - 1;
		}
	}
	cout << l << '\n';
	return 0;
}