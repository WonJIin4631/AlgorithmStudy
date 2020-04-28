#include<iostream>
using namespace std;

int N, M;
long long list[100001];
long long ans;
void solve() {
	long long left = 1;
	long long right = M*list[N-1];
	long long mid;
	ans = right;
	while (left<=right){
		long long sum = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			sum += mid / list[i];
		}
		if (sum < M)
			left = mid + 1;
		else {
			if (mid <= ans)
				ans = mid;
			right = mid - 1;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> list[i];
	solve();
	cout << ans << '\n';
	return 0;
}