#include<iostream>
#include<string>

using namespace std;


string S;
string wordList[100];
int dp[101] = { 0 };
int N;
int main() {
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wordList[i];
	}
	dp[S.length()] = 1;
	for (int pos = S.length() - 1; pos >= 0; pos--) {
		for (int i = 0; i <= N; i++) {
			if (S.find(wordList[i], pos) == pos && dp[pos + wordList[i].length()] == 1) {
				dp[pos] = 1;
				break;
			}
			else
				dp[pos] = 0;
		}
	}
	cout << dp[0]<<'\n';
	return 0;
}