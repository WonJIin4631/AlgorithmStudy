#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

void getcount(int n) {
	int cnt = 1;
	while (--n) {
		cnt = cnt * 2 + 1;
	}
	printf("%d\n", cnt);
}
void solve(int n, int from, int by, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		solve(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		solve(n - 1, by, from, to);
	}
}
int main() {
	int N;
	scanf("%d", &N);
	getcount(N);
	solve(N, 1, 2, 3);
	return 0;
}