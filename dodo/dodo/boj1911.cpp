#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Info{
	int st;
	int end;
};
struct comp{
	bool operator()(Info a, Info b) {
		return a.st < b.st;
	}
};
vector<Info> v;
int N, L;
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(),comp());

	int cur = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (cur < v[i].st) {
			cur = v[i].st;
		}
		while (true) {
			if (cur >= v[i].end)
				break;
			ans++;
			cur += L;
		}
	}
	cout << ans << '\n';
	return 0;
}