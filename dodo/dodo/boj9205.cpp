#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

typedef pair<int, int> pii;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N;
		pii st_pos;
		pii end_pos;
		cin >> N;
		vector<pii> v;
		cin >> st_pos.first >> st_pos.second;
		v.push_back(st_pos);
		for (int i = 1; i <= N; i++) {
			pii info;
			cin >> info.first >> info.second;
			v.push_back(info);
		}
		cin >> end_pos.first >> end_pos.second;
		v.push_back(end_pos);
		sort(v.begin(), v.end(),greater<pii>());
		int stIdx;
		int endIdx;

		for (int i = 0; i < v.size(); i++) {
			if (st_pos.first == v[i].first&&st_pos.second== v[i].second)
				stIdx = i;
			if (end_pos.first == v[i].first&&end_pos.second == v[i].second)
				endIdx = i;
		}
		if (stIdx == endIdx)
			cout << "happy" << '\n';
		else {
			bool flag = false;
			pii temp;
			if (stIdx > endIdx) {
				temp = st_pos;
				for (int i = stIdx; i >= endIdx; i--) {
					if (20 < (abs(temp.first - v[i].first) + abs(temp.second - v[i].second)) / 50) {
						flag = true;
						break;
					}
					temp = v[i];
				}
			}
			else {
				temp = st_pos;
				for (int i = stIdx; i <= endIdx; i++) {
					if (20 < (abs(temp.first - v[i].first) + abs(temp.second - v[i].second)) / 50) {
						flag = true;
						break;
					}
					temp = v[i];
				}
			}
			if (flag)
				cout << "sad" << '\n';
			else
				cout << "happy" << '\n';
		}
		v.clear();
	}
	return 0;
}