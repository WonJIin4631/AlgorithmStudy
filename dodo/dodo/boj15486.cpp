#include<iostream>
#include<algorithm>
using namespace std;

int day[1500003] = { 0 };
int money[1500003] = { 0 };
int dp[1500003] = { 0 };
int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> day[i] >> money[i];
	}
	int cur_max = 0;
	for (int i= 1; i <= N+1; i++) {
		cur_max = max(cur_max, dp[i]);
		if (i + day[i] > N + 1)
			continue;
		dp[i + day[i]] = max(cur_max + money[i], dp[i + day[i]]);
	}
	cout<< cur_max << '\n';
	return 0;
}