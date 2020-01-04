#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;


vector<int> su1;
vector<int> su2;

void solve() {
	int su1_idx = 0;
	int su2_idx = 0;
	int ans = 0;
	int su1_sum = 0;
	int su2_sum = 0;
	while (true)
	{
		//끝일때
		if (su1_idx == su1.size()) {
			for (int i = su2_idx; i < su2.size();i++) {
				su2_sum += su2[i];
			}
			ans += max(su2_sum,su1_sum);
			break;
		}
		else if (su2_idx == su2.size()) {
			for (int i = su1_idx; i < su1.size(); i++) {
				su1_sum += su1[i];
			}
			ans += max(su2_sum, su1_sum);
			break;
		}
		//같을때
		else if (su1[su1_idx] == su2[su2_idx]) {
			ans += max(su1_sum, su2_sum)+su1[su1_idx];
			su1_idx++;
			su2_idx++;
			su1_sum = 0;
			su2_sum = 0;	
		}
		//1이 작을때
		else if (su1[su1_idx] < su2[su2_idx]) {
			su1_sum += su1[su1_idx];
			su1_idx++;
		}
		//2가 작을때
		else if (su1[su1_idx] > su2[su2_idx]) {
			su2_sum += su2[su2_idx];
			su2_idx++;
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			su1.push_back(num);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			su2.push_back(num);
		}
		solve();
		su1.clear();
		su2.clear();
	}
	return 0;
}