#include<iostream>
#include<algorithm>
using namespace std;

int N;
int map[21][21];
int citySum[6] = { 0 };
int totalSum = 0;
int ans = 987654321;
void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			totalSum += map[i][j];
		}
	}
}

bool checkPosible(int idx, int d1, int d2) {
	bool flag = true;
	int x = idx % N;
	int y = idx / N;
	if ((d1 + d2) < 0 || (y + d1 + d2) >= N)
		flag = false;
	if ((x - d1) < 0 || (x + d2) >= N)
		flag = false;
	return flag;
}
void getCitySum(int idx,int d1,int d2) {
	int x = idx %N;
	int y = idx / N;
	int tempSum = totalSum;
	//1번 
	int tx = x;
	for (int i = 0; i < y + d1; i++) {
		if (i < y) {
			for (int j = 0; j <= x; j++)
				citySum[1] += map[i][j];
		}
		else {
			for (int j = 0; j < tx; j++)
				citySum[1] += map[i][j];
			tx--;
		}
	}

	tx = x;
	//2번
	for (int i = 0; i <= y + d2; i++) {
		if (i < y) {
			for (int j = x + 1; j < N; j++)
				citySum[2] += map[i][j];
		}
		else {
			tx++;
			for (int j = tx; j < N; j++)
				citySum[2] += map[i][j];
		}
	}
	//3번
	tx = x-d1;
	for (int i = y+d1; i < N; i++) {
		if (i <= y+d1+d2) {
			for (int j = 0; j < tx; j++)
				citySum[3] += map[i][j];
			tx++;
		}
		else {
			for (int j = 0; j < x-d1+d2; j++)
				citySum[3] += map[i][j];
		}
	}
	//4번
	tx = x+d2;
	for (int i = y + d2+1; i < N; i++) {
		if (i <= y + d1 + d2) {
			for (int j = tx; j <N; j++)
				citySum[4] += map[i][j];
			tx--;
		}
		else {
			for (int j = x-d1+d2; j < N; j++)
				citySum[4] += map[i][j];
		}
	}
	int minVal = 987654321;
	int maxVal = 0;

	for (int i = 1; i <= 4; i++) {
		tempSum -= citySum[i];
		minVal = min(minVal, citySum[i]);
		maxVal = max(maxVal, citySum[i]);
		citySum[i] = 0;
	}
	minVal = min(minVal, tempSum);
	maxVal = max(maxVal, tempSum);
	ans = min(ans, maxVal - minVal);
}
void solve() {
	for (int idx = 0; idx < N*N; idx++) {
		for (int d1 = 1; d1 < N; d1++) {
			for (int d2 = 1; d2 < N; d2++) {
				if (checkPosible(idx, d1, d2)) {
					getCitySum(idx, d1, d2);
				}
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	init();
	solve();

	return 0;
}