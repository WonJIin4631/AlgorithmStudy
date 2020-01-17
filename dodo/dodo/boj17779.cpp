#include<iostream>
#include<algorithm>
using namespace std;

int N;
int map[22][22];
int ans = 987654321;
int total=0;
void div(int y,int x,int d1,int d2) {
	int sum = 0;
	int idx = 0;
	int min_v = 987654321;
	int max_v = 0;
	int city5 = total;
	//1备开
	for (int i = 1; i < y; i++) {
		if (i < y - d1) {
			for (int j = 1; j <= x+d1; j++) {
				sum += map[i][j];
			}
		}
		else {
			for (int j = 1; j < x+d1-idx; j++) {
				sum += map[i][j];
			}
			idx++;
		}
	}
	min_v = min(sum, min_v);
	max_v = max(sum, max_v);
	city5 -= sum;
	//3备开
	sum = 0;
	idx = 0;
	for (int i = y; i <= N; i++) {
		if (i < y + d2) {
			for (int j = 1; j < x + idx; j++) {
				sum += map[i][j];
			}
			idx++;
		}
		else {
			for (int j = 1; j < x + d2; j++) {
				sum += map[i][j];
			}
		}
	}
	min_v = min(sum, min_v);
	max_v = max(sum, max_v);
	city5 -= sum;
	//2备开
	sum = 0;
	idx = 0;
	for (int i = 1; i <= y-d1+d2; i++) {
		if (i <= y - d1) {
			for (int j = x+d1+1; j <= N; j++) {
				sum += map[i][j];
			}
		}
		else {
			idx++;
			for (int j = N; j > x + d1 + idx; j--) {
				sum += map[i][j];
			}
		}
	}
	min_v = min(sum, min_v);
	max_v = max(sum, max_v);
	city5 -= sum;
	//4备开
	sum = 0;
	idx = 0;
	for (int i = y - d1 + d2+1; i <= N; i++) {
		if (i <= y + d2) {
			idx++;
			for (int j = N; j >x+d1+d2-idx; j--) {
				sum += map[i][j];
			}
		}
		else {
			for (int j = x+d2; j <=N; j++) {
				sum += map[i][j];
			}
		}
	}
	min_v = min(sum, min_v);
	max_v = max(sum, max_v);
	city5 -= sum;
	//5备开
	sum = 0;
	idx = 0;
	min_v = min(city5, min_v);
	max_v = max(city5, max_v);
	ans = min(ans, max_v - min_v);
}
void solve() {
	for (int i = 2; i <= N-1; i++) {
		for (int j = 1; j <= N; j++) {
			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					if (j + d1 + d2 >= N)
						continue;
					if (1 > i - d1 || N <= i + d2)
						continue;
					div(i, j, d1, d2);
				}
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			total += map[i][j];
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}