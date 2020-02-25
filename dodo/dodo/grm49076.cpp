#include <iostream>
#include<deque>
using namespace std;
int N, M;
deque<char> dq1;
deque<char> temp;
/*
���� �̿��Ͽ� �տ������� ���������� �̾Ƽ� �ٽ� �ֱ�
M�� �̻� �������� �ִ�
���� ���� �ٸ� ���� ���ö����� �̱� M�� �̸��̸� �ٽ� �ֱ�
���ʿ��� ���� �����°��̶� �ѹ������� temp�� �ִ°� �ٽóְ� ó������ Ž�� �ݺ�
*/

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		dq1.push_back(c);
	}
	while (true) {
		bool flag = true;
		while (!dq1.empty()) {
			char cur = dq1.front();
			int cnt = 1;
			dq1.pop_front();
			while (!dq1.empty()) {
				if (cur == dq1.front()) {
					dq1.pop_front();
					cnt++;
				}
				else
					break;
			}
			if (cnt >= M) {
				flag = false;
				break;
			}
			else {
				for (int j = 0; j < cnt; j++)
					temp.push_back(cur);
			}
		}
		int tsz = temp.size();
		for (int j = 0; j < tsz; j++) {
			char t = temp.back();
			temp.pop_back();
			dq1.push_front(t);
		}
		if (flag)
			break;
	}
	if (dq1.empty())
		cout << "CLEAR!" << '\n';
	else {
		for (int i = 0; i < dq1.size(); i++)
			cout << dq1[i];
	}
	return 0;
}