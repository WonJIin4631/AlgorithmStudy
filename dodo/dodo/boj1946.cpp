#include<iostream>
#include<algorithm>
using namespace std;

int N,T;
int ans;
pair<int, int> sawon[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> sawon[i].first >> sawon[i].second;
		}
		sort(sawon, sawon + N);
		ans = 1;
		int val = sawon[0].second;
		for (int i = 1; i < N; i++) {
			if (sawon[i].second < val) {
				val = sawon[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}