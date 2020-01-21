#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long n;
			cin >> n;
			ans += n;
		}
	}
	cout << ans << '\n';
	return 0;
}