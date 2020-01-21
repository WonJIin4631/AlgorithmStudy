#include<iostream>
#include<algorithm>
using namespace std;
long long N, M;
long long maxCnt;
long long ans = 1e9;
void solve(long long cnt,long long val) {
	if (cnt > maxCnt||ans<cnt)
		return;
	if (val == M) {
		ans = min(ans, cnt);
		return;
	}
	if(val*2<=M)
		solve(cnt + 1, val * 2);
	if(val*10+1<=M)
		solve(cnt + 1, val * 10 + 1);
}
int main() {
	
	cin >> N >> M;
	maxCnt = M / 2;
	solve(0, N);
	if (ans == 1e9)
		ans = -1;
	else
		ans += 1;
	cout << ans << '\n';
	return 0;
}