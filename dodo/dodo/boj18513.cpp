#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;

vector<int> v;
int N, K;
int moveP[2] = { -1,1 };
set<int> Set;
typedef pair<int, int> pii;
int main() {
	cin >> N >> K;
	v.resize(N + 1);
	queue<pii> q;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		Set.insert(v[i]);
		q.push(pii(v[i],v[i]));
	}
	int wide = 1;
	int cnt = 0;
	long long ans = 0;
	bool flag = false;
	while (!q.empty()) {
		int cur = q.front().first;
		int from = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (cnt == K) {
				flag = true;
				break;
			}
			int p = cur +moveP[i];
			if (Set.find(p) == Set.end()) {
				Set.insert(p);
				ans += abs(p-from);
				cnt++;
				q.push(pii(p,from));
			}
		}
		if (flag)
			break;
	}

	cout << ans << '\n';
	return 0;
}