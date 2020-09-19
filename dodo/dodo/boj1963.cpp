#include <iostream>
#include <queue>
using namespace std;

int change_prime(int n, int i, int j) {
	int k = n;
	if (i == 1) {
		k -= (n / 1000) * 1000;
		k += j * 1000;
	}
	else if (i == 2) {
		k -= ((n / 100) % 10) * 100;
		k += j * 100;
	}
	else if (i == 3) {
		k -= ((n % 100) / 10) * 10;
		k += j * 10;
	}
	else if (i == 4) {
		k -= n % 10;
		k += j;
	}
	return k;
}

int main() {
	int prime[10000] = { 0 };
	for (int i = 1001; i<10000; i++) {
		prime[i] = 1;
		for (int j = 2; j<i; j++) {
			if (i%j == 0) {
				prime[i] = 0;
				break;
			}
		}
	}

	int K;
	cin >> K;

	int n1, n2, cnt;
	for (int testCase = 0; testCase<K; testCase++) {
		scanf("%d %d", &n1, &n2);

		int visited[10000] = { 0 };

		queue<pair<int, int>> q;
		visited[n1]++;
		q.push(make_pair(n1, 0));

		bool check = false;

		while (!q.empty()) {
			n1 = q.front().first;
			cnt = q.front().second;
			q.pop();

			if (n1 == n2) {
				printf("%d\n", cnt);
				check = true;
				break;
			}

			int n = 0;
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j <= 9; j++) {
					n = change_prime(n1, i, j);
					if (n<1000 || visited[n] || prime[n] == 0)
						continue;

					visited[n]++;
					q.push(make_pair(n, cnt + 1));
				}
			}

		}

		if (!check) {
			printf("Impossible\n");
		}
	}
	return 0;
}