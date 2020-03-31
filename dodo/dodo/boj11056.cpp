#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
2���� ���ڿ��� �ִ� �κ� ���ڿ��� ���̵��� �� ���ѵ�
2���� ���ڿ� ���̿��� ����.
*/
int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;
	int dp[1002][1002] = { 0 };
	int ans = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans =max(ans,dp[i][j]);
			}
		}
	}
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ans << '\n';
}