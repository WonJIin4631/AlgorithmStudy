#include<iostream>
#include<math.h>
using namespace std;
/*
�����佺�׳׽��� ü�� �̿��Ͽ� ����Ǯ��

*/
int arr[1000002] = { 0 };
int M, N;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(N); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= N; j += i) {
			arr[j] = 0;
		}
	}
	for (int i = M; i <= N; i++) {
		if(arr[i]!=0)
			cout << arr[i] << '\n';
	}
	return 0;
}