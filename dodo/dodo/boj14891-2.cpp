#include<iostream>
#include<deque>
#include<vector>
#include<math.h>
using namespace std;

deque<int> gear[4];
typedef pair<int, int> pii;
vector<pii> v;
int ans = 0;
int K;
void move_gear(int idx, int dir) {
	if (dir == -1) {
		int temp=gear[idx].front();
		gear[idx].pop_front();
		gear[idx].push_back(temp);
	}
	else {
		int temp = gear[idx].back();
		gear[idx].pop_back();
		gear[idx].push_front(temp);
	}
}
void solve() {
	int turn = 0;
	while (turn<v.size()){
		int cur = v[turn].first;
		int dir = v[turn].second;
		int leftCnt = 0;
		int rightCnt = 0;
		for (int i = cur - 1; i > 0; i--) {
			if (gear[i][6] != gear[i - 1][2])
				leftCnt++;
			else
				break;
		}
		for (int i = cur - 1; i < 3; i++) {
			if (gear[i][2] != gear[i + 1][6])
				rightCnt++;
			else
				break;
		}
		move_gear(cur-1, dir);
		int lTemp = dir;
		for (int i = 1; i <= leftCnt; i++) {
			lTemp *= -1;
			move_gear(cur-1-i, lTemp);
		}
		int rTemp = dir;
		for (int i = 1; i <= rightCnt; i++) {
			rTemp *= -1;
			move_gear(cur-1 + i, rTemp);
		}
		turn++;
	}
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			ans += pow(2, i);
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		int n;
		for (int j = 0; j<8; j++) {
			scanf("%1d", &n);
			gear[i].push_back(n);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int from, dir;
		scanf("%d %d", &from, &dir);
		v.push_back(pii(from, dir));
	}
	solve();
	printf("%d", ans);
	return 0;
}