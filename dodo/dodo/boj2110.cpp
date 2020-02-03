#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
한집에 공유기 1개설치 가능 두 공유기 사이의 거리를 가능한 크게
C개의 공유기를 N개의 집에 적당히설치 
가장 인접한 두 공유기 거리를 최대로


*/
int main() {
	vector<long long> v;

	int N, C;
	cin >> N >> C;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long left = 1;
	long long right = v.back() - v.front();

	int ans = 0;
	long long dist = 0;
	while (left<=right){
		long long mid = (left + right) / 2;
		long long start = v[0];
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			dist = v[i] - start;
			if (mid <= dist) {
				++cnt;
				start = v[i];
			}
		}
		if (cnt >= C) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}