#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int start;
	int end;
};

bool operator<(Info a, Info b) {
	if (a.end != b.end)
		return a.end > b.end;
	else
		return a.start > b.start;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int start, end;
	priority_queue<Info> pq;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		pq.push({ start, end });
	}
	int ans = 0;
	end = -1;
	while (!pq.empty()) {
		Info cur = pq.top();
		pq.pop();

		if (cur.start >= end) {
			ans++;
			end = cur.end;
		}
	}
	cout << ans << endl;
	return 0;
}
