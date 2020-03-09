#include<iostream>
#include<string>
#include<cstring>
using namespace std;
/*
�� �ڸ����� �ִ���̱��� �Ӹ������ ���Ѵ�
���̰� 1�γ��������Ŵ� ������ �Ӹ����

*/
string s;
bool dp[2502][2502];
int cnt[2502];
int main() {
	cin >> s;
	memset(dp, false, sizeof(dp));
	int len = s.length();
	s.insert(0, " ");
	//���� 1
	for (int i = 1; i <= len; i++) 
		dp[i][i] = true;
	//���� 2
	for (int i = 1; i <= len - 1; i++)
		if (s[i] == s[i + 1])
			dp[i][i + 1] = true;
	
	//���� 3�̻�
	for (int i = 2; i < len; i++) {
		for (int j = 1; j <= len - i; j++) {
			if (s[j] == s[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i]=true;
		}
	}
	cnt[0] = 0;
	for (int i = 1; i <= len; i++) {
		cnt[i] = 2500;
		for (int j = 1; j <= i; j++) {
			if (dp[j][i]) {
				if (cnt[i] > cnt[j - 1] + 1) {
					cnt[i] = cnt[j - 1] + 1;
				}
			}
		}
	}
	cout << cnt[len] << '\n';
	return 0;
}