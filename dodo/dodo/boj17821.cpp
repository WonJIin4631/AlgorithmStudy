#include<iostream>
#include<algorithm>

using namespace std;

int N;
int record[51][10];
int player[10];
int ans = 0;
int play() {
	int score = 0;
	int cur_player = 1;
	int pllist[10];
	for (int i = 1; i <= 3; i++) {
		pllist[i] = player[i+1];
	}
	pllist[4] = player[1];
	for (int i = 5; i <= 9; i++) {
		pllist[i] = player[i];
	}
	for (int i = 0; i < N; i++) {
		int out = 0;
		int base[4] = {0};
		while (true)
		{	
			//10번이면 1번으로 바꾸기
			if (cur_player == 10)
				cur_player = 1;
			//타자번호
			int pn = pllist[cur_player];
			//3아웃시 종료
			if (out == 3) 
				break;
			
			if (record[i][pn] == 0) {
				out++;
			}
			//1루타,2루타,3루타,홈런 설정
			else if (record[i][pn] == 1) {
				if (base[3] == 1) {
					base[3] = 0;
					score++;
				}
				if (base[2] == 1) {
					base[2] = 0;
					base[3] = 1;
				}
				if (base[1] == 1) {
					base[1] = 0;
					base[2] = 1;
				}
				base[1] = 1;
			}
			else if (record[i][pn] == 2) {
				if (base[3] == 1) {
					base[3] = 0;
					score++;
				}
				if (base[2] == 1) {
					base[2] = 0;
					score++;
				}
				if (base[1] == 1) {
					base[1] = 0;
					base[3] = 1;
				}
				base[2] = 1;
			}
			else if (record[i][pn] == 3) {
				if (base[3] == 1 ) {
					base[3] = 0;
					score++;
				}
				if (base[2] == 1) {
					base[2] = 0;
					score++;
				}
				if (base[1] == 1) {
					base[1] = 0;
					score++;
				}
				base[3] = 1;
			}
			else if (record[i][pn] == 4) {
				int cnt = 0;
				for (int j = 1; j <= 3; j++) {
					if (base[j]) {
						base[j] = 0;
						cnt++;
					}
				}
				score+=cnt+1;
			}
			cur_player++;
		}
	}
	return score;
}

void solve() {
	do {
		int val = play();
		if (ans < val)
			ans = val;
	} while (next_permutation(player+2, player + 10));
}

int main() {
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		player[i]=i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> record[i][j];
		}
	}
	solve();
	cout << ans << '\n';
}