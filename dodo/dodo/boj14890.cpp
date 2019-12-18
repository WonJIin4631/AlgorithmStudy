#include<iostream>
using namespace std;

int map[101][101];
int N, L;

int check[101][101];
int ans = 0;


void down() {
	for (int i = 0; i < N; i++) {
		int start = map[i][0];
		for(int j=1;j<N;j++){
			if (start > map[i][j] + 1 || start < map[i][j]-1) {
				break;
			}
			//오르막
			if (start+1 == map[i][j]) {
				if (j + 1 - L >= 0) {
					int cnt = 0;
					for (int k = j - 1; k >= j + 1 - L; k--) {
						if (start == map[i][k]&&check[i][k]==0) {
							check[i][k] = 1;
							cnt++;
						}
					}
					if (cnt < L) {
						break;
					}
				}
				else 
					break;
			}
			//내리막
			if (start -1 == map[i][j]) {
				if (j + L -1< N) {
					int cnt = 0;
					for (int k = j; k <= j + L-1; k++) {
						if (start == map[i][k] && check[i][k] == 0) {
							check[i][k] = 1;
							cnt++;
						}
					}
					if (cnt < L) {
						break;
					}
				}
				else
					break;
			}

		}
	}

}
void left() {
	int check[101][101];
	for (int i = 0; i < N; i++) {
		int start = map[i][0];
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (start == map[i][j])
				cnt++;
			//높은거
			else if (start == map[i][j] - 1) {
				if (cnt >= L) {
					start = map[i][j];
					cnt = 1;
				}
				else
					break;
			}
			//낮은거
			else if (start == map[i][j] + 1) {
				if (j + L < N) {
					int cnt2 = 0;
					int ss = map[i][j];
					for (int k = j; k < j + L; k++) {
						if (ss == map[i][k])
							cnt2++;
					}
					if (cnt2 >= L) {
						cnt = 1;
						start = map[i][j + L];
					}
					else
						break;
				}
				else
					break;
			}
			else if (start <map[i][j] - 1 || start>map[i][j] + 1)
				break;
			if (j == N - 1) {
				ans++;
			}
		}
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//left();
	down();
	cout << ans << '\n';
}