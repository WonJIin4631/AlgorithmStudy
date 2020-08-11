#include<iostream>
using namespace std;

int arr[100001];

int N, S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int s = 0, e = 0;
	int sum = arr[0];
	int len = 0;
	int ans = 100000001;
	while (s <= e&&e < N) {
		if (sum < S) {
			if (e < N) {
				e++;
				sum += arr[e];
			}
		}
		else if (sum >= S) {
			len = e - s + 1;
			if (ans > len) {
				ans = len;
			}
			if (s <= e) {
				sum -= arr[s];
				s++;
			}
		}
	}
	if (ans == 100000001)
		ans = 0;
	cout << ans << '\n';
	return 0;
}