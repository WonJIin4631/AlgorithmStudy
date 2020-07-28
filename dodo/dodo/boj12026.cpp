#include<iostream>
#include<algorithm>
using namespace std;


char input[1001];
int N;
int dp[1001] = { 0 };
bool checkPrev(char cur, char prev) {
	if (cur == 'B') {
		if (prev == 'J')
			return true;
	}
	else if (cur == 'O') {
		if (prev == 'B')
			return true;
	}
	else if (cur == 'J') {
		if (prev == 'O')
			return true;
	}
	return false;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		if (i > 0)
			dp[i] = 987654321;
	}
	for (int i = 1; i < N; i++) {
		char cur = input[i];
		for (int j = i - 1; j >= 0; j--) {
			if (checkPrev(cur, input[j])) {
				dp[i] = min(dp[i], dp[j] + ((i - j)*(i - j)));
			}
		}
	}
	if (dp[N - 1] == 987654321)
		cout << -1 << '\n';
	else
		cout << dp[N - 1] << '\n';
	return 0;
}