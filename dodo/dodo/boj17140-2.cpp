#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int map[103][103] = { 0 };
int r, c, k;
int maxR = 3;
int maxC = 3;
int time = 0;
int numlist[102] = { 0 };
typedef pair<int, int> pii;
int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	vector<pii> v;
	while (true) {
		if (map[r][c] == k)
			break;
		//R연산
		if (time >= 100) {
			time = -1;
			break;
		}
		if (maxR >= maxC) {
			int tempC=0;
			for (int i = 1; i <= maxR; i++) {
				int maxNum = 0;
				for (int j = 1; j <= maxC; j++) {
					if (map[i][j] == 0)
						continue;
					numlist[map[i][j]]++;
					maxNum = max(map[i][j], maxNum);
					map[i][j] = 0;
				}
				for (int j = 1; j <= maxNum; j++) {
					if (numlist[j] != 0) {
						v.push_back(pii(numlist[j], j));
						numlist[j] = 0;
					}
				}
				sort(v.begin(), v.end());
				int idx = 1;
				int sz = v.size() * 2;
				tempC = max(tempC,sz);
				for (int j = 0; j < v.size(); j++) {
					map[i][idx++] = v[j].second;
					map[i][idx++] = v[j].first;
					if (idx == 100)
						break;
				}
				v.clear();
			}
			maxC = tempC;
		}
		//C연산
		else {
			int tempR = 0;
			for (int i = 1; i <= maxC; i++) {
				int maxNum = 0;
				for (int j = 1; j <= maxR; j++) {
					if (map[j][i] == 0)
						continue;
					numlist[map[j][i]]++;
					maxNum = max(map[j][i], maxNum);
					map[j][i] = 0;
				}
				for (int j = 1; j <= maxNum; j++) {
					if (numlist[j] != 0) {
						v.push_back(pii(numlist[j], j));
						numlist[j] = 0;
					}
				}
				sort(v.begin(), v.end());
				int idx = 1;
				int sz = v.size() * 2;
				tempR = max(tempR, sz);
				for (int j = 0; j < v.size(); j++) {
					map[idx++][i] = v[j].second;
					map[idx++][i] = v[j].first;
					if (idx == 100)
						break;
				}
				v.clear();
			}
			maxR = tempR;
		}
		time++;
	}
	cout << time << '\n';
	return 0;
}