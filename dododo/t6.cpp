#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	int count = 0;
	cin >> a >> b >> c;
	while (b != c) {
		b = b / 2 + b % 2;
		c = c / 2 + c % 2;
		count++;
	}
	cout << count << endl;
}