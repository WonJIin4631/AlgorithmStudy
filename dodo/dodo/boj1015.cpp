#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int main() {
	cin >> N;
	vector<int> v(N);
	int num[1001];
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i <= 1000; i++) {
		num[i] = -1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		num[v[i]] = i;
	}

}