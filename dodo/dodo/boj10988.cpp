#include<iostream>
#include<string>
using namespace std;
bool ans = true;
/*
문자열의 반만큼 왼쪽 오른쪽 비교하면서 길이를 증가
만약 다르다면 break

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