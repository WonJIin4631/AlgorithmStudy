#include<iostream>
#include<algorithm>
using namespace std;
/*
���л� 2,���л� 1�� �����̴�.
N���� ���л��� M���� ���л� 
K���� �ݵ�� ���Ͻ��� �����ؾߵ�, ���Ͻ� �����ϰ� �Ǹ� �л��� ��ȸ�� ���� �Ұ���
���� �ִ밪 ���
�ִ� ���ǰ��� 50���� ���⼭ 0������ ���� �������鼭 ��?
*/
int N, M, K;
int team = 50;
int main() {
	cin >> N >> M >> K;
	while (true){
		if (team * 2 <= N&&team <= M) {
			if (team * 2 + team <= N + M - K)
				break;
		}
		team--;
	}
	cout << team << '\n';
	return 0;
}