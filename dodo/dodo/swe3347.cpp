#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	vector<pair<int, int>> v;
	int arr[1001] = { 0 };
	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;
		int maxVal = 0;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			maxVal = max(num, maxVal);
			v.push_back(make_pair(num, i));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			int minIdx = 1001;
			for (int j = 0; j < N; j++) {
				if (num < v[j].first)
					break;
				minIdx = min(minIdx, v[j].second);
			}
			arr[minIdx]++;
		}
		int ans;
		int val = 0;
		for (int i = 0; i < maxVal; i++) {
			if (val < arr[i]) {
				ans = i;
				val = arr[i];
			}
		}
		cout << '#' << tc << ' ' << ans+1 << '\n';
		memset(arr,0, sizeof(arr));
		v.clear();
	}
	return 0;
}