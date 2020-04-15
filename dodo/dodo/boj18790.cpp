#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> ans;
vector<int> v;
bool flag = false;
void solve(int idx,int sum,int cnt) {
	if (sum %N==0&&sum!=0 && cnt == N) {
		int temp = 0;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		flag = true;
		exit(0);
	}
	if (cnt > N)
		return;
	for (int i = idx; i <v.size(); i++) {
		ans.push_back(v[i]);
		solve(i + 1, sum + v[i], cnt + 1);
		ans.pop_back();
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	solve(0, 0, 0);
	if (!flag)
		cout << "-1" << '\n';
	return 0;
}