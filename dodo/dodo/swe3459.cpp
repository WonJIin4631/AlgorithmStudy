#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long n;
		cin >> n;
		long long sum = 1;
		int powNum = 1;
		if (n == 1) {
			cout << "Bob" << '\n';
		}
		else {
			while (true)
			{
				if (n < sum) {
					if (powNum % 2 == 0)
						cout << '#' << t << ' ' << "Alice" << '\n';
					else
						cout << '#' << t << ' ' << "Bob" << '\n';
					break;
				}
				sum += pow(2, powNum);
				cout << sum << ' ' << pow(2, powNum) << ' ' << powNum << '\n';
				powNum++;
			}
		}
	}
	return 0;
}