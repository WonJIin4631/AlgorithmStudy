#include<iostream>
#include<vector>
using namespace std;

/*
에라토스테네스의 체를활용
O(n log log n) 시간복잡도
*/
vector<int> v;
int N;
int arr[1002];
int n_list[1002];

int main() {
	cin >> N;
	for (int i = 2; i <= 1000; i++) {
		arr[i] = i;
	}
	int cnt = 0;
	for (int i = 2; i <= 1000; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= 1000; j+=i) {
			arr[j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> n_list[i];
		if (arr[n_list[i]] != 0)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}