#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
bool check[10002] = { 0 };
vector<int> v;
vector<int> ans;
void DFS(int idx, int cnt,vector<int> &a) {
	if (cnt == M) {
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		a.push_back(v[i]);
		DFS(i, cnt + 1, a);
		a.pop_back();
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (!check[num]) {
			check[num] = true;
			v.push_back(num);
		}
	}
	sort(v.begin(), v.end());
	DFS(0, 0, ans);
	return 0;
}