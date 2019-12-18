#include<iostream>
#include<vector>
using namespace std;


/*
4�� �� 10�� �ֻ��� ��
���� �̵� ���⶧ ��ġ ���� �߰�
�����ڸ��� �̵� �Ұ�
������ġ �̻� ���� ������ġ
������ġ �� �̵� �ȵ�
*/


int move_list[11];
int map[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0/*�������21*/,10,13,16,19,25/*������ 26*/,20,22,24,25,30,35,40/*���� 33*/,30,28,27,26,25 /*���� 38*/};
int mal[5] = { 0 };
int summal[5] = { 0 };
int visit[47];
bool fin[5] = { false };
int ans = 0;
int change(int cur,int num) {

	int n_pos =num + cur;
	if (cur >= 0 && cur <= 20) {
		if (n_pos == 5)
			return 22;
		if (n_pos == 10)
			return 27;
		if (n_pos == 15)
			return 34;
		if (n_pos > 20)
			return 21;
	}
	else if (cur >= 22 && cur <= 26) {
		if (n_pos >= 30)
			return 21;
		if (n_pos == 29)
			return 20;
		else if (n_pos == 26)
			return 30;
		else if (n_pos > 26)
			return 30 - (26 - cur) + num;
	}
	else if (cur >= 27 && cur <= 33) {
		if (n_pos == 33)
			return 20;
		if (n_pos > 33)
			return 21;
	}
	else if (cur >= 34 && cur <= 38) {
		if (n_pos >= 42)
			return 21;
		if (n_pos == 41)
			return 20;
		else if (n_pos == 38)
			return 30;
		else if(n_pos>38)
			return 30 - (38 - cur) + num;
	}
	return n_pos;
}
void solve(int cnt,int sum) {
	if (cnt == 10) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		//���� ��ġ�� �ִ¸� �̵�����
		if (mal[i] == 21)
			continue;
		int curpos = mal[i];
		int nextpos = change(curpos, move_list[cnt]);
		//���� �ڸ��� ���� ��ġ�ϸ� �ȿ�����
		if (visit[nextpos] == 1)
			continue;
		//���� ����ÿ�
		if (nextpos == 21) {
			visit[curpos] = 0;
			mal[i] = nextpos;
			solve(cnt + 1, sum);
			mal[i] = curpos;
			visit[curpos] = 1;
		}
		//�ƴҽ�
		else {
			visit[curpos] = 0;
			visit[nextpos] = 1;
			mal[i] = nextpos;
			solve(cnt + 1, sum+map[mal[i]]);
			mal[i] = curpos;
			visit[curpos] = 1;
			visit[nextpos] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> move_list[i];
	}
	solve(0,0);
	cout << ans << '\n';
}