#include<iostream>
using namespace std;

/*
���� ������ �� �������� ��� ĭ�� ���̰� ���ƾߵ� ��, ���θ� ���� �������� �ִ� ���� ����� �ִ�. ���� ���̴� ������ 1 ���̴� L
�������� ���� �ִ� -> ���� ������ �ݴ��� ������ ���� �ִ�.
���� ����
���δ� ���� ĭ�� ��ġ, L���� ���ӵ� ĭ �ٴڿ� ��� ����
����ĭ ���� ĭ ���� ���� ������ 1

���� �ߺ� ��ġ X

���� ������ 2����-> ������, ������
��, �� ���� ���� �ľ�
1. ���̰� ���� ���� �ľ�
2. ���ΰ� ������� �� �̿� ���θ� �ξ� Ȯ��
���� ������ ���������� ������ ���ο� �°� �̵����� ���ʿ����� �̵����� �ϸ� �ȵ�

*/

int map[101][101];
int hang[101] = { 0 };
int yeol[101] = { 0 };
int ans = 0;
int N, L;

void solve() {
	// ��
	for (int i = 0; i < N; i++) {
		int prev_height = map[i][0];
		int same_cnt = 1;
		bool flag = true;
		int temp[101] = { 0 };
		//1�� ������ -1�� ������
		for (int j = 1; j < N; j++) {
			if (!flag)
				break;
			if (prev_height == map[i][j]) {
				same_cnt++;
				continue;
			}
			//�������� 1���� Ŭ���
			if (prev_height + 1 < map[i][j])
				flag = false;
			else if (prev_height - 1 > map[i][j])
				flag = false;
			//�������� �������
			else if (prev_height + 1 == map[i][j]) {
				//���� ĭ ����
				if (j - L < 0 || same_cnt < L)
					flag = false;
				else {
					for (int k = j - L; k < j; k++) {
						if (temp[k] == 0)
							temp[k] = 1;
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[i][j];
				same_cnt = 1;
			}
			//�������� �������
			else if (prev_height - 1 == map[i][j]) {
				//���� ĭ ����
				if (j + L - 1 >= N)
					flag = false;
				else {
					for (int k = j; k < j + L; k++) {
						if (temp[k] == 0 && map[i][j] == map[i][k]) {
							temp[k] = -1;
						}
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[i][j];
				j += L-1;
				same_cnt = L;
			}
		}
		if (!flag)
			continue;
		//�ݴ��ʿ��� ���� ���� Ȯ���ϸ�
		for (int j = N - 1; j >= 1; j--) {
			if (!flag)
				break;
			if (map[i][j] == map[i][j - 1])
				continue;
			if (map[i][j] == map[i][j - 1] + 1) {
				if (temp[j - 1] != 1)
					flag = false;
			}
			if (map[i][j] == map[i][j - 1] - 1) {
				if (temp[j] != -1)
					flag = false;
			}
		}
		if (flag)
			hang[i] = 1;
	}
	//��
	for (int i = 0; i < N; i++) {
		int prev_height = map[0][i];
		int same_cnt = 1;
		bool flag = true;
		int temp[101] = { 0 };
		//1�� ������ -1�� ������
		for (int j = 1; j < N; j++) {
			if (!flag)
				break;
			if (prev_height == map[j][i]) {
				same_cnt++;
				continue;
			}
			//�������� 1���� Ŭ���
			if (prev_height + 1 < map[j][i])
				flag = false;
			if (prev_height - 1 > map[j][i])
				flag = false;
			//�������� �������
			else if (prev_height + 1 == map[j][i]) {
				//���� ĭ ����
				if (j - L < 0 || same_cnt < L)
					flag = false;
				else {
					for (int k = j - L; k < j; k++) {
						if (temp[k] == 0)
							temp[k] = 1;
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[j][i];
				same_cnt = 1;
			}
			//�������� �������
			else if (prev_height - 1 == map[j][i]) {
				//���� ĭ ����
				if (j + L - 1 >= N)
					flag = false;
				else {
					for (int k = j; k < j + L; k++) {
						if (temp[k] == 0 && map[j][i] == map[k][i]) {
							temp[k] = -1;
						}
						else {
							flag = false;
							break;
						}
					}
				}
				prev_height = map[j][i];
				j += L - 1;
				same_cnt = L;
			}
		}
		if (!flag)
			continue;


		for (int j = N - 1; j >= 1; j--) {
			if (!flag)
				break;
			if (map[j][i] == map[j - 1][i])
				continue;
			if (map[j][i] == map[j - 1][i] + 1) {
				if (temp[j - 1] != 1)
					flag = false;
			}
			if (map[j][i] == map[j - 1][i] - 1) {
				if (temp[j] != -1)
					flag = false;
			}
		}
		if (flag)
			yeol[i] = 1;
	}
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	for (int i = 0; i < N; i++) {
		if (hang[i] == 1)
			ans++;
		if (yeol[i] == 1)
			ans++;
	}
	cout<<ans<<'\n';
	return 0;
}