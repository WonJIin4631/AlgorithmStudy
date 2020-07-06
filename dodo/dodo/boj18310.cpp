#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321
int N;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		sum += p;
		v.push_back(p);

	}
	sort(v.begin(), v.end());
	cout << v[(N- 1) / 2] << '\n';
	return 0;
}