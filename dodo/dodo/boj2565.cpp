#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;
vector<int> ans;
int main() {
	ans.push_back(0);
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (ans.back() < v[i].second) {
			ans.emplace_back(v[i].second);
		}
		else {
			auto it = lower_bound(ans.begin(), ans.end(), v[i].second);
			*it = v[i].second;
		}
	}

	cout << v.size() - (ans.size() - 1);
	return 0;
}