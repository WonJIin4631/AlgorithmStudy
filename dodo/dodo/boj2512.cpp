#include<iostream>
#include<algorithm>
using namespace std;
/*
이분탐색으로 예산금액 최대값 찾기
범위 -> 0~ 제일 큰 예산요청

*/
int N, M;
int list[10002];
int main() {
	cin >> N;
	int maxN=0;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		maxN = max(maxN, list[i]);
	}
	cin >> M;
	int left = 0;
	int right = maxN;
	while (left<=right){
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (list[i] < mid)
				sum += list[i];
			else
				sum += mid;
		}
		if (sum > M) {
			right = mid - 1;
		}
		else {
			left = mid +1;
		}
	}
	cout << left-1 << '\n';
}