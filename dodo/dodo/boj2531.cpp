#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

struct Info {
	int num;
	int pos;
};
int N, D, K, C;
int chobab[30010];
int check_chobab[3010] = { 0 };
int ans = 0;
queue<Info> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> D >> K >> C;
	for (int i = 1; i <= N; i++) {
		cin >> chobab[i];
		if (i > K)
			q.push({ chobab[i],i });
	}
	int cnt = 0;
	for (int i = 1; i <= K; i++) {
		q.push({ chobab[i],i });
		if (check_chobab[chobab[i]] == 0) {
			cnt++;
		}
		check_chobab[chobab[i]]++;
	}
	if (check_chobab[chobab[C]] == 0)
		ans = max(cnt + 1, ans);
	else
		ans = max(cnt, ans);
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		if (check_chobab[cur.num] == 0) {
			cnt++;
		}
		check_chobab[cur.num]++;
		int prev = cur.pos - K;
		if (prev >= 1) {
			if (check_chobab[chobab[prev]] == 1) {
				cnt--;
			}
			check_chobab[chobab[prev]]--;
		}
		else {
			if (check_chobab[chobab[N + prev]] == 1) {
				cnt--;
			}
			check_chobab[chobab[N + prev]]--;
		}
		if (ans <= cnt) {
			if (check_chobab[C] == 0) {
				ans = cnt + 1;
			}
			else
				ans = cnt;
		}
	}
	cout << ans << '\n';
	return 0;
}