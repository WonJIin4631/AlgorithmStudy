#include<iostream>
#include<string>
#include<string.h>
using namespace std;

/*
�������� �ڿ��� N�� ���ڸ��� �� N�� ���� ��Ÿ��

�������� ��� ���� ���� �����ڸ� ���

����� ���ϱ� N 9*N�ڸ��� ��ŭ �� �� ���� ���ۺ��� N ���ϱ��� 
���� �������� N�� ���ٸ� �ݺ��� �ߴ� ���
N ���� ũ�� ������ �ݺ��� �ߴ� ���
*/
int list[1000002] = { 0 };
int main() {
	int num = 1;
	int N;
	cin >> N;
	if (N > 100) {
		string s = to_string(N);
		num = N - s.length() * 9;
	}
	while (true){
		string s = to_string(num);
		int temp = num;
		for (int i = 0; i < s.length(); i++) {
			int n = s[i] - '0';
			temp += n;
		}
		if(num>N)
			break;
		if (temp == N) {
			list[temp] = num;
			break;
		}
		num++;
	}
	cout << list[N] << '\n';
	return 0;
}
