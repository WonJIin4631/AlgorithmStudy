#include<iostream>
using namespace std;

int N, S, M;
bool check[101][1001] = { 0 };
int main() {
	cin >> N >> S >> M;
	check[0][S] = true;
	int val;
	for (int i = 1; i <= N; i++) {
		cin >> val;
		for (int j = 0; j <= M; j++) {
			if (check[i - 1][j]) {
				if(j+val<=M)
					check[i][j + val] = true;
				if (j - val >= 0)
					check[i][j - val] = true;
			}
		}
	}
	int ans = -1;
	for (int i = M; i >=0; i--) {
		if (check[N][i]) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}