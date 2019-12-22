#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<functional>
using namespace std;

int T, N, M;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		cin >> M;
		sort(v.begin(), v.end());
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (binary_search(v.begin(),v.end(),num)) {
				cout << '1' << '\n';
			}
			else {
				cout << '0' << '\n';
			}
		}
		v.clear();
	}
}