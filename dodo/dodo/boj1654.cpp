#include<iostream>
#include<algorithm>
using namespace std;
/*
K개 랜선을 가지고 있다 N개의 같은 길이의 랜선으로 만들어야 한다

0~최대 길이의 랜선 범위에서
이분탐색을 해서 출력한다.
갯수가 많으면 길이을 늘리고 갯수가 적으면 길이를 줄인다.
*/
int K, N;
long long line[10002];
long long ans;
int main() {
	long long left, right, mid;
	left=right = 1;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> line[i];
		right = max(right, line[i]);
	}
	while (true){
		mid = (left + right) / 2;
		if (left > right) {
			ans = mid;
			break;
		}
		long long temp = 0;
		for(int i=0;i<K;i++){
			temp += line[i] / mid;
		}
		if (temp >= N) {
			left = mid+1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}