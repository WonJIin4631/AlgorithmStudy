#include <iostream>
using namespace std;

int coins[11];
int N, K;
int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> coins[i];

	int result = 0;

	for (int i = 1; i <= N; i++) {
		result += K / coins[N - i];
		K %= coins[N - i];
		if (K == 0)
			break;
	}
	cout << result<<'\n';
	return 0;
}