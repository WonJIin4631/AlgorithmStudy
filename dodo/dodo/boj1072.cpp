#include<iostream>
using namespace std;

long long X, Y,Z;
int ans = -1;
int main() {
	cin >> X >> Y;
	Z = Y * 100 / X + 1;
	if (Z == 100||Z==101)
		cout << -1<< '\n';
	else {
		long long left = 1;
		long long right = 1000000000;
		while (left <= right) {
			long long mid = (left + right) / 2;
			long long percent = (Y + mid) * 100 / (X + mid);
			if (Z <= percent) {
				right = mid-1;
				ans = mid;
			}
			else if (Z >= percent)
				left = mid + 1;
		}
		cout << ans << '\n';
	}

	return 0;
}