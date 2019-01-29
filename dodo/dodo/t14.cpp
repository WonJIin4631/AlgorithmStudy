#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char a[101];
	int check[26] = { 0 };
	int position[26]; fill_n(position, 26, -1);
	cin >> a;
	for (int i = 0; i < strlen(a); i++) {
		int val = a[i]-97;
		if (check[val] == 0) {
			position[val] = i;
			check[val] = 1;
		}
	
	for (int i = 0; i < 26; i++) {
		cout << position[i] << " ";
	}

}