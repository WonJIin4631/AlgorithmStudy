#include <iostream>
using namespace std;

int N, K;
int arr[1001] = { 0 };
int main(){
	cin >> N >> K;

	for (int i = 2; i <= N; ++i) {
		for (int j = i; j <= N; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
				--K;
			}
			if (K == 0) {
				cout << j << '\n';
				break;
			}
		}
		if (K == 0)
			break;
	}
	return 0;
}