#include<iostream>
#include<algorithm>
using namespace std;

int A, B, C;
int time[102] = { 0 };
int minTime = 102;
int maxTime = 0;
int val[4] = { 0 };
int ans = 0;
int main() {
	cin >> val[1] >> val[2] >> val[3];
	for (int i = 0; i < 3; i++) {
		int st, end;
		cin >> st >> end;
		minTime = min(st, minTime);
		maxTime = max(end, maxTime);
		for (int j = st; j < end; j++) {
			time[j]++;
		}
	}
	for (int i = minTime; i < maxTime; i++) {
		ans += val[time[i]]*time[i];
	}
	cout << ans << '\n';
	return 0;
}