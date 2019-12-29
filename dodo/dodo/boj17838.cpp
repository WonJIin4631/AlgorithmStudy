#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int T;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		if (s.length() == 7) {
			if (s[0] == s[1] && s[2] == s[3] && s[0] == s[4] && s[5] == s[6] && s[5] == s[2]&&s[0]!=s[2])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}