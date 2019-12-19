#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> v;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int sz = v.size();
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int val = v[i] * (sz - i);
		if (ans < val)
			ans = val;
	}
	cout << ans << '\n';
}