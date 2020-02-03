#include<iostream>
#include<vector>
using namespace std;

/*
�ڿ��� K 3�̻� 1000����
ũ�� 1001 �迭 ����
0�������� 1�� ����

DFS�� ����� Ž��
���� 
3���� �ﰢ���� ���ؼ� ã������ ���� ���;ߵ� �̸�, �ʰ� �ȵ�
3�� �̸����� ã������ ������ ũ�� �Ǹ� Ž�� �� �ʿ����
���ü� �ִ°�쿡�� ���̻� ã�� �ʾƵ� ��
*/
int T;
vector<int> v;
int num;
bool flag;
void DFS(int cnt,int sum) {
	if (cnt == 3) {
		if (sum == num)
			flag = true;
		return;
	}
	if (flag)
		return;
	if (sum > num)
		return;
	for (int i = 0; i < v.size(); i++) {
		DFS(cnt + 1, sum + v[i]);
	}
}
int main() {
	int curIdx = 1;
	while (true){
		int checkPos=curIdx*(curIdx+1)/2;
		if (checkPos > 1000)
			break;
		v.push_back(checkPos);
		curIdx++;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		flag = false;
		cin >> num;
		DFS(0, 0);
		if (flag)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}