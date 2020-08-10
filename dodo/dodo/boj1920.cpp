#include<iostream>
#include<algorithm>
using namespace std;

int arr[100000 + 1] = { 0 };
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	int n;
	int idx = 0;
	for (int i = 0; i < M; i++) {
		cin >> n;
		if (binary_search(arr, arr + N, n))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
