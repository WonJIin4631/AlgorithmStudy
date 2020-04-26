#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N;
int list[2001];
int val[2001] = { 0 };
int ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		val[i] = 1;
	}

	if (N == 1)
		cout << 0 << '\n';
	else {

		for (int i = 1; i < N; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (list[i] < list[j]) {
					val[i] = max(val[j] + 1, val[i]);
				}
			}
			ans = max(val[i], ans);
		}
		cout << N - ans << '\n';
	}

	return 0;
}