#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct KS
{
	int from;
	int to;
	int val;
};
int parent[100001];
int ans;
bool check;
vector<KS> v;

int find(int n) {
	if (n == parent[n])
		return n;
	return parent[n] = find(parent[n]);
}

void merge(int f, int t) {
	check = false;
	f = find(f);
	t = find(t);
	if (f == t)
		return;
	parent[f] = t;
	check = true;
}
bool comp(KS k1, KS k2) {
	return k1.val < k2.val;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		KS ks;
		cin >> ks.from >> ks.to >> ks.val;
		v.push_back(ks);
	}
	sort(v.begin(), v.end(), comp);
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		merge(v[i].from, v[i].to);
		if (check && (cnt < N - 2)) {
			ans += v[i].val;
			cnt++;
		}
	}
	cout << ans << '\n';
	return 0;
}