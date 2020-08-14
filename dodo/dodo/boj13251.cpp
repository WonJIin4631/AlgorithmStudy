#include<iostream>
using namespace std;
int list[51];
int sum;
int M, K;
double ans;
int main() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
		sum += list[i];
	}
	cin >> K;
	if (K == 1 || M == 1)
		ans = 1.0;
	else {
		for (int i = 0; i < M; i++) {
			int tempSum = sum;
			int tempCnt = list[i];
			double tempVal = 1;
			for (int i = 0; i < K; i++) {
				tempVal *= ((double)tempCnt-- / (double) tempSum--);
			}
			ans += tempVal;
		}
	}
	cout.precision(20);
	cout << ans << '\n';
	return 0;
}