#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int N, M;
int sz;
vector<int> v;
vector<int> num;
set<int> Set;
void solve(int cnt,int idx) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < sz; i++) {
		v.push_back(num[i]);
		solve(cnt + 1,i);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (Set.find(n) == Set.end()) {
			Set.insert(n);
			num.push_back(n);
		}
	}
	sort(num.begin(), num.end());
	sz = num.size();
	solve(0,0);
	return 0;
}