#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
struct Info {
	int x;
	int y;
};
vector<Info> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int stx,sty;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		Info info;
		cin >> info.x >> info.y;
		if (i == 0) {
			stx = info.x; sty = info.y;
		}
		v.push_back(info);
		ans += abs(stx - info.x) + abs(sty - info.y);
		stx = info.x; sty = info.y;
	}
	int dist = 0;
	for (int i = 1; i < N-1; i++) {
		Info prev, cur, next;
		prev = v[i - 1]; cur = v[i]; next = v[i + 1];
		int temp = abs(prev.x - cur.x) + abs(prev.y - cur.y) + abs(cur.x - next.x) + abs(cur.y - next.y);
		int jump = abs(prev.x - next.x) + abs(prev.y - next.y);
		dist = max(dist, temp - jump);
	}
	cout << ans - dist << '\n';
	return 0;
}