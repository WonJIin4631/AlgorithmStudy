#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int N;
	long long prev = 1;
	long long next = 10;
	int len = 1;
	long long sum = 0;

	cin >> N;
	while (1) {
		bool exit = false;
		for (int i = prev; i < next; i++) {
			if (i > N) {
				exit = true;
				break;
			}
			sum += len;
		}
			if (exit)
				break;

			prev *= 10;
			next *= 10;
			len += 1;
		
	}
	cout << sum << endl;
}