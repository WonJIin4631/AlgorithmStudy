#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
string num;
void dfs(int cur, int cnt) {
	if (cnt == n) {
		ans = max(ans, stoi(num));
		return;
	}
	for (int i = cur; i<num.size(); i++) {
		for (int j = i + 1; j<num.size(); j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(i, cnt + 1);
				swap(num[i], num[j]);
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> num >> n;
		ans = 0;
		dfs(0, 0);
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
