#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= 2*N-1; i++) {
		int s = i <= N ? i : 2 * N - i;
		for (int j = 1; j < s; j++) {
			cout << ' ';
		}
		for (int j = 2*N-1; j >= 2*(s-1)+1; j--) {
			cout << '*';
		}
		cout << endl;
	}

}