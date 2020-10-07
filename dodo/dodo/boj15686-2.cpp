#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info{
	int x;
	int y;
};
vector<Info> chick;
vector<Info> house;
bool checkChick[13] = { 0 };
int N, M;
int map[51][51];
int ans = 987654321;
int getDist() {
	int dist = 0;
	for (int i = 0; i < house.size(); i++) {
		int minDist = 987654321;
		for (int j = 0; j < chick.size(); j++) {
			if (checkChick[j]) {
				int calDist = abs(chick[j].x - house[i].x) + abs(chick[j].y - house[i].y);
				minDist = min(minDist, calDist);
			}
		}
		dist += minDist;
	}
	return dist;
}
void chooseChik(int idx,int cnt) {
	if (cnt == M) {
		ans = min(ans, getDist());
		return;
	}
	if (idx == chick.size())
		return;
	checkChick[idx] = true;
	chooseChik(idx + 1, cnt+1);
	checkChick[idx] = false;
	chooseChik(idx + 1, cnt);

}
void solve() {
	if (chick.size() != M) {
		chooseChik(0, 0);
	}
	else {
		for (int i = 0; i < M; i++)
			checkChick[i] = true;
		ans = min(ans, getDist());
	}
	cout << ans << '\n';
}
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back({ j,i });
			else if (map[i][j] == 2)
				chick.push_back({ j,i });
		}
	}
}
int main() {
	init();
	solve();
	return 0;
}