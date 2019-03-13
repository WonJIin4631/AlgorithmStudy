#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> v;
	int N, M;
	cin >> N >> M;
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N + M; i++) {
		cout << v.at(i) << ' ';
	}
}