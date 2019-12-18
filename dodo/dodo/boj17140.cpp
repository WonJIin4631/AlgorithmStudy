#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, k;
int map[101][101];
int maxR=3;//За
int maxC=3;//ї­
int ans = 0;

void clear(char rc,int line,int max_N) {
	if (rc == 'R') {
		for (int i = 0; i < max_N; i++) {
			map[line][i] = 0;
		}
	}
	else {
		for (int i = 0; i < max_N; i++) {
			map[i][line] = 0;
		}
	}
}
void calR() {
	vector<pair<int, int>> v;
	int curMR = 0;
	for (int i = 0; i < maxC; i++) {
		int num[102] = { 0 };
		int maxN = 0;
		for (int j = 0; j < maxR; j++) {
			if (map[i][j] == 0)
				continue;
			num[map[i][j]]++;
			if (maxN < map[i][j])
				maxN = map[i][j];
		}
		for (int j = 1; j <= maxN; j++) {
			if (num[j] == 0)
				continue;
			v.push_back(make_pair(num[j],j));
		}
		sort(v.begin(), v.end());
		int idx = 0;
		clear('R', i, maxR);
		if(curMR<v.size()*2)
			curMR = v.size() * 2;
		for (int j = 0; j < v.size(); j++) {
			map[i][idx++] = v[j].second;
			map[i][idx++] = v[j].first;
		}
		v.clear();
	}
	maxR = curMR;
}
void calC() {
	vector<pair<int, int>> v;
	int curMC = 0;
	for (int i = 0; i < maxR; i++) {
		int num[102] = { 0 };
		int maxN = 0;
		for (int j = 0; j < maxC; j++) {
			if (map[j][i] == 0)
				continue;
			num[map[j][i]]++;
			if (maxN < map[j][i])
				maxN = map[j][i];
		}
		for (int j = 1; j <= maxN; j++) {
			if (num[j] == 0)
				continue;
			v.push_back(make_pair(num[j], j));
		}
		sort(v.begin(), v.end());
		int idx = 0;
		clear('C', i, maxC);
		if (curMC<v.size() * 2)
			curMC = v.size() * 2;
		for (int j = 0; j < v.size(); j++) {
			map[idx++][i] = v[j].second;
			map[idx++][i] = v[j].first;
		}
		v.clear();
	}
	maxC = curMC;
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		if (map[r-1][c-1] == k) {
			cout << ans << '\n';
			break;
		}
		if (ans > 100) {
			cout << -1 << '\n';
			break;
		}
		if (maxC >= maxR) {
			calR();
		}
		else {
			calC();
		}
		ans++;
	}
}