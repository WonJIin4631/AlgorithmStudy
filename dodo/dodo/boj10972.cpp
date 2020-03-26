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
	if (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	
	return 0;
}