#include<iostream>
using namespace std;
/*
구간의 최대 최소값의 차이는 0~9999까지 나올수 있다
구간점수 값을 이분탐색으로 나눠지는 구간의 개수를 비교하면서 탐색
구간이 많이 나누어지면 구간차이값 높게
구간이 적게 나누어지면 구간차이값 낮게

*/
int N, M;
int list[5002];
//몇구간으로 나누어지는지 확인
int check(int n) {
	int min_n = list[0];
	int max_n = list[0];
	int res = 1;
	for (int i = 1; i < N; i++) {
		//최소값 확인
		if (list[i] < min_n)
			min_n = list[i];
		//최대값 확인
		if (list[i] > max_n)
			max_n = list[i];
		//최대 최소값의 차이가 현재 기준 차이값보다 크면 구간짜름
		if (max_n - min_n > n)
			min_n = max_n = list[i], res++;
	}
	//현재까지 짤려진 구간의 개수 반환
	return res;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int l = 0;
	int r = 9999;
	//최대값 기준으로 구간을 나눔 
	//이분탐색으로 구간의 기준을 나눔
	int c;
	while (l <= r) {
		//
		c = (l + r) / 2;
		//M보다 구간이 많이 나누어 졋을때
		if (check(c) > M) {
			l = c + 1;
		}
		//M보다 구간이 적게 나누어 졋을때
		else {
			r = c - 1;
		}
	}
	cout << l << '\n';
	return 0;
}