#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int check[26] = { 0 };
	int position[26]; fill_n(position, 26, -1);
	cin >> s;
	for (int i = 0; i < s.length; i++) {
		int val = s[i] - 97;
		if (check[val] == 0) {
			position[val] = i;
			check[val] = 1;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << position[i] << " ";
	}
	return 0;
}