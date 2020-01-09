#include<cstdio>
int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		long long n;
		scanf("%llu", &n);
		int check = 0;
		long long turn = 1;
		long long mul = 1;
		while (turn < n) {
			if (!check)
				mul *= 4;
			turn += mul;
			check = !check;
		}
		printf("#%d %s\n", t, check ? "Alice" : "Bob");

	}
	return 0;
}
