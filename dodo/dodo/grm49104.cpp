#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
int day[200002] = { 0 };
int N;
/*
상여금 기준으로 내림차순으로 정렬
선택된 금액에서 마감일 기준으로 이하인거 탐색하다 0인거 있으면 거기다 답넣기


*/
bool comp(pii a, pii b) {
	return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int ans = 0;
	int maxD = 0;
	for (int i = 0; i < N; i++) {
		int m, d;
		cin >> m >> d;
		maxD = max(maxD, d);
		v.push_back(pii(m, d));
	}
	sort(v.begin(), v.end(), comp);
	int cnt = maxD;
	for (int i = 0; i < N; i++) {
		if (cnt == 0)
			break;
		int idx = v[i].second;
		int money = v[i].first;
		if (day[idx] == 0) {
			day[idx] = money;
			ans += money;
			cnt--;
		}
		else {
			while (day[--idx]);
			if (idx != 0) {
				day[idx] = money;
				ans += money;
				cnt--;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}