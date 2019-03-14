#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int s;
	for (int i = 1; i <= (2*N)-1; i++) {
		s = (i <= N) ? i : 2*N-i;
		for (int j = 1; j <= s ; j++) {
			cout << '*';
		}
		for (int k = N * 2 - s * 2; k >= 1; k--) {
			cout << ' ';
		}
		for (int l = 1; l <= s; l++) {
			cout << '*';
		}
		cout << endl;
	}
}