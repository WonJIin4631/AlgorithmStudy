#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
������ ������ 1����ġ ���� �� ������ ������ �Ÿ��� ������ ũ��
C���� �����⸦ N���� ���� ��������ġ 
���� ������ �� ������ �Ÿ��� �ִ��


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