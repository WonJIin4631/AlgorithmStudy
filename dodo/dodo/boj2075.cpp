#include<iostream>
#include<queue>
using namespace std;

/*
merge sort �ð����⵵ O(nlogn)
n�� 1500*1500
14292410�� ����-> �޸����� 10Mb�̶� �ȵ�(int ���� 32��Ʈ 4����Ʈ)
���� ����ؼ� �ذ�
*/
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N*N; i++) {
		//���� �Է�
		int num;
		cin >> num;
		//�켱���� ť�� N������������ �ֱ�
		if (pq.size() < N)
			//�켱����ť ���� ������ �����ؼ� ���������� -> ��ȣ�� �ٲپ ū���� ���� ���������� ����
			pq.push(num*-1);
		//N�ʰ��� ���
		else {
			//���� ���� �� ���� ū���̸� ���� ������ ����
			if (pq.top()*-1 < num) {
				pq.pop();
				pq.push(num*-1);
			}
			else
				continue;
		}
	}
	cout << pq.top()*-1 << '\n';
	return 0;
}