#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


int power[50001] = { 0 };
int check[50001] = { 0 };
int N;
typedef pair<int, int> pii;
vector<pii> v;
vector<int> ans;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> power[i];
		v.push_back(pii(power[i], i));
	}
	sort(v.begin(), v.end(), greater<>());
	int leftM = N;
	int idx = 0;
	while (true) {
		if (leftM == 0)
			break;
		if (check[v[idx].second] == 0) {
			ans.push_back(v[idx].second + 1);
			int curPower = v[idx].first;
			int cIdx = v[idx].second;
			check[cIdx] = 1;
			leftM--;
			for (int i = cIdx - 1; i >= 0; i--) {
				if (check[i] != 0) {
					break;
				}
				if (power[i] < curPower) {
					curPower = power[i];
					check[i] = 1;
					leftM--;
				}
				else
					break;
			}
			curPower = v[idx].first;
			for (int i = cIdx + 1; i < N; i++) {
				if (check[i] != 0) {
					break;
				}
				if (power[i] < curPower) {
					curPower = power[i];
					check[i] = 1;
					leftM--;
				}
				else
					break;
			}
		}
		idx++;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}