#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
��� ,+,- ��ȣ ���� ���̰� 50�� ���� ����� ��ȣ�� ����
���� 0~9 ,+,- ������ �̷�����ִ� ����ó�� ������ ���ڴ� ����, �����ؼ� 2�� ������ X ,5�ڸ����� ���� ���� X, ���� 0���� ���۰���

������ ��������  ���� ��� DFS�� �̿�?
1.���� ������ ��,������ ��ȣ�� ����
2.��ȣ ���� ��������
��ȣ�� ���� ���̰� 50�ʰ��ϸ� �ȵ�

�ּҰ��� �������� -���� �����ڰ� -�� �ٽ� ���ö����� ��ȣ ���� ������ �ٷ� ������ ��ȣ ���ص���

��ȣ �����ؼ� 50�̻��̸� �ȵ��� �ʳ�?
*/

vector<char> op;
vector<int> num;
int len;
int ans = 987654321;
void solve(int idx, int sum,int galho) {

	if (idx >= op.size()) {
		ans = min(ans, sum);
		return;
	}
	if (op[idx] == '-') {
		if (idx < op.size()-1) {
			if (op[idx + 1] != '-') {
				int ncnt = 0;
				int temp = num[idx+1];
				for (int i = idx + 1; i < op.size(); i++) {
					if (op[i] == '-')
						break;
					ncnt++;
				}
				for (int i = idx + 1; i < idx + 1 + ncnt ; i++) {
					temp += num[i+1];
				}
				solve(idx + ncnt+1, sum - temp, galho + 2);
			}
		}
		solve(idx + 1, sum - num[idx + 1], galho);
	}
	else {
		solve(idx + 1, sum + num[idx + 1], galho);
	}
}

int main() {
	string s;
	cin >> s;
	string sNum="";
	int opIdx = 0;
	int numIdx = 0;
	len = s.length();
	cout << len << '\n';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			num.push_back(stoi(sNum));
			op.push_back(s[i]);
			sNum = "";
		}
		else {
			sNum += s[i];
		}
	}
	num.push_back(stoi(sNum));
	solve(0, num[0], 0);
	cout << ans << '\n';
	return 0;
}