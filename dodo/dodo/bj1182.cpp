#include<iostream>
using namespace std;

#define MAX_N 20
int arr[MAX_N];
int cnt = 0;
int N, S;


void find(int idx, int sum) {
	sum += arr[idx];
	
	if (idx >= N)
		return;

	if (sum == S)
		cnt++;

	find(idx + 1, sum - arr[idx]);
	find(idx + 1, sum);

}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	find(0, 0);
	cout << cnt << endl;

}
