#include<iostream>
#include<algorithm>
using namespace std;
int A, B, C;
double X, Y;
int ans = 999999999;


int main() {
	cin >> A >> B >> C >> X >> Y;
	int sol = A * X + B * Y;
	ans=min(ans, sol);
	int lc = min(X, Y);
	if (lc == X) {
		sol = 2 * C*lc + (Y-X) * B;
	}
	else if(lc == Y){
		sol = 2 * C*lc + (X-Y) * A;
	}
	ans = min(ans, sol);
	lc = max(X, Y);
	sol = 2 * C *lc;
	ans = min(ans, sol);
	cout << ans;
}