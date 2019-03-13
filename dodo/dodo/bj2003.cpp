#include<iostream>
using namespace std;

int main() {
	int N, M;
	int arr[10000+1];
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int sum = arr[i];
		if (sum != M) {
			for (int j = i + 1; j < N; j++) {
				sum += arr[j];
				if (sum == M) {
					cnt++;
					break;
				}
				else if (sum > M) {
					break;
				}
			}
		}
		else
			cnt++;
	}
	cout << cnt <<endl;
}