#include<iostream>
#include<algorithm>	
using namespace std;
/*
��� 2���� ���� ģ�� �� ����� �������� ��� ����� ���Ը�ŭ ����, �������� 0���ϰ� �Ǹ� ����
1�� ��Ģ ���� ���� ����� ���
2�� �տ� ����ִ� ������� ������ ���� ��� �� �ϳ��� ģ�� �տ� �ִ°���� �����ų� ������ ���� �ٸ� ����� ������ ġ�� �ʰ� �Ѿ�� ���Ŀ� ��� ����ġ �� 3������ ����
3�� ���� �ֱٿ� �� ��� ��ĭ ������ ��� �տ��� 2������ ���� ���� �ֱٿ� ģ ����� ���� �������̸� ����

���� �ִ� ����� �ִ� ������ ���
DFS�� ���ؼ� ���ǿ� �´� ��쿡 ���ؼ� ����Ž�� �Ͽ� ������ �ذ�

*/
int eggS[8 + 1];
int eggW[8 + 1];
int N, ans;

bool isBroken(int idx) {
	if (eggS[idx] <= 0)
		return true;
	else
		return false;
}

void DFS(int idx) {
	if (idx == N) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (isBroken(i))
				count++;
		}
		ans = max(ans, count);
		return;
	}
	if (isBroken(idx)) {
		DFS(idx+ 1);
		return;
	}
	bool check = true;

	for (int i = 0; i < N; i++) {
		if (i == idx || isBroken(i))
			continue;
		eggS[idx] -= eggW[i];
		eggS[i] -= eggW[idx];
		DFS(idx + 1);
		check = false;
		eggS[idx] += eggW[i];
		eggS[i] += eggW[idx];

	}
	if (check)
		DFS(idx + 1);

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> eggS[i] >> eggW[i];
	}
	ans = 0;
	DFS(0);
	cout << ans << '\n';
	return 0;
}