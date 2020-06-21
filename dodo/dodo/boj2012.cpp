#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> list;
int N;
long long ans = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		list.push_back(n);
	}
	sort(list.begin(), list.end());
	int grade = N;
	for (int i = list.size() - 1; i >= 0; i--) {
		if (list[i] != grade)
			ans += abs(grade - list[i]);
		grade--;
	}
	cout << ans << '\n';
	return 0;
}