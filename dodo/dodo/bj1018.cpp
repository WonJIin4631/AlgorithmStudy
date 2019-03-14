#include<iostream>
#include<vector>
using namespace std;

#define MAX_SIZE 50

int N, M;
char map[MAX_SIZE+1][MAX_SIZE+1];
int cnt;
int lesscnt = 999999999;
void change(char s, int x, int y) {
	cnt = 0;
	if (s == 'W') {
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i + j) % 2 == 0) {
					if (map[i][j] != 'W')
						cnt++;
				}
				else {
					if (map[i][j] != 'B')
						cnt++;
				}
			}
		}
	}	
	else {
		for (int i = x; i < x + 8; i++) {
			for (int j = y; j < y + 8; j++) {
				if ((i + j) % 2 == 0) {
					if (map[i][j] != 'B')
						cnt++;
				}
				else {
					if (map[i][j] != 'W')
						cnt++;
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= N - 7; i++) {
		for (int j = 1; j <= M - 7; j++) {
			change('W', i, j);
			if (lesscnt > cnt)
				lesscnt = cnt;
			change('B', i, j);
			if (lesscnt > cnt)
				lesscnt = cnt;
		}
	}
	cout << lesscnt << '\n';
}