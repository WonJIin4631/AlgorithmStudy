#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		cin >> a >> b;
		ans = max(cur - a, ans);
		cur -= a;
		ans = max(cur + b, ans);
		cur += b;
	}
	cout << ans << '\n';
	return 0;
}