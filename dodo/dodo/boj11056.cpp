#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s1;
string s2;
int dp[1002][1002] = { 0 };
int lcs(int i, int j) {
	if (i == -1 || j == -1) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	else if (s1[i] == s2[j]) {
		return dp[i][j] = lcs(i - 1, j - 1) + 1;
	}
	else if (s1[i] != s2[j]) {
		return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
	}
}
int main() {
	cin >> s1 >> s2;
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			dp[i][j] = -1;
	int ans = s1.length() + s2.length() - lcs(s1.length() - 1, s2.length() - 1);
	/*
	int maxLen = max(s1.length(), s2.length());
	for (int i = 0; i < maxLen; i++) {
		for (int j = 0; j < maxLen; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	cout << ans << '\n';
	return 0;
}