#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = N; i>=1; i--) {
		for (int j = N; j > i; j--) {
			cout << ' ';
		}
		for (int k = 1; k <= (i * 2) - 1; k++) {
			cout << '*';
		}
		cout << endl;
	}
}