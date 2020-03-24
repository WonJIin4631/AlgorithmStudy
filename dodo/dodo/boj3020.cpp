#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
������ ���̴� N ���� ���̴� H�̴�.
¦���� ����������(������) Ȧ���� �Ʒ��� ����(����)
���˹����� ������ ������ ���������� �̵��ϸ鼭 ��ֹ��� ��� �ı�

������ ���� 1~ �ִ���� �̺�Ž��
������ �������� ������ ������ ���� ���̱�
�ݴ�� ���� ���̱�

������ ����,������ ���� 0~�ִ� ���̱��� ������ �迭�� ����
1~H������ ����,������ ������ ���ϱ�
1~H ������ �� ������ ���� ���� �����ϰ� ���� ���̸� anscnt�� ����
*/
int N, H;
int seok[500001] = { 0 };
int jong[500001] = { 0 };
int hList[5000001];
int ans = 987654321;
int anscnt = 0;
int main() {
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		int u, d;
		cin >> u >> d;
		seok[d]++;
		jong[u]++;
	}
	for (int i = H-1; i >=1; i--)
		seok[i] += seok[i + 1];
	for (int i = H-1; i >=1; i--)
		jong[i] += jong[i + 1];
	for (int i = 1; i <= H; i++)
		hList[i] = seok[i] + jong[H - i + 1];
	sort(hList, hList + H);
	for (int i = 1; i <= H; i++) {
		if (hList[i] < ans) {
			ans = hList[i];
			anscnt = 1;
		}
		else if (hList[i] == ans)
			anscnt++;
	}
	cout << ans << ' ' << anscnt << '\n';
	return 0;
}