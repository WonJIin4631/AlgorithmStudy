#include<iostream>
#include<string>
using namespace std;
int N, M;
string s;
int cnt = 0;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'I'&&s[i + 1] == 'O') {
			int On = 0;
			while (s[i + 1] == 'O'&&s[i + 2] == 'I') {
				i += 2;
				On++;
				if (s[i] == 'I'&&On == N) {
					On--;
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}