#include<iostream>
#include<string>
using namespace std;
bool ans = true;
/*
���ڿ��� �ݸ�ŭ ���� ������ ���ϸ鼭 ���̸� ����
���� �ٸ��ٸ� break

*/
int main() {
	string s;
	cin >> s;
	int len;
	len = s.length() / 2;
	for (int i = 0; i < len; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			ans = false;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}