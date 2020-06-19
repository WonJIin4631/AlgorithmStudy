#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> v;
	vector<int> ::iterator low;
	vector<int> ::iterator high;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int j = 0; j < M; j++) {
		int n;
		cin >> n;
		low = lower_bound(v.begin(), v.end(), n);
		high = lower_bound(v.begin(), v.end(), n + 1);
		cout << high - low << ' ';
	}

	return 0;
}