#include<iostream>
#include<math.h>
using namespace std;
int N,R,C;
int ans = 0;
int main() {
	cin >>N>> R >> C;
	int y = pow(2, N) / 2;
	int x = y;
	while (N> 0) {
		N--;
		int temp = pow(2, N) / 2;
		int sum = pow(4, N);
		if (R < y && C < x) {
			x -= temp;
			y -= temp;
		}
		else if (R < y && x <= C) {
			x += temp;
			y -= temp;
			ans += sum;
		}
		else if (y <= R && C < x) {
			x -= temp;
			y += temp;
			ans += sum * 2;
		}
		else {
			x += temp;
			y += temp;
			ans += sum * 3;
		}
	}
	cout << ans << '\n';
	return 0;
}