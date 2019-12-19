#include<iostream>

using namespace std;

int T;
int K;
int tobny[1002][9];
int connect[1001];
int ans = 0;
void turn(int idx, int dir) {
	if (dir == 1) {
		int temp = tobny[idx][7];
		for (int i = 7; i >= 1; i--) {
			tobny[idx][i] = tobny[idx][i - 1];
		}
		tobny[idx][0] = temp;
	}
	else {
		int temp = tobny[idx][0];
		for (int i = 1; i <=7; i++) {
			tobny[idx][i-1] = tobny[idx][i];
		}
		tobny[idx][7] = temp;
	}
}
void check_con() {
	for (int i = 2; i <= T; i++) {
		if (tobny[i - 1][2] != tobny[i][6]) {
			connect[i-1] = 1;
		}
		else {
			connect[i-1] = 0;
		}
	}
}
void solve(int idx,int dir) {
	check_con();
	turn(idx, dir);
	int lcon,rcon;
	int ldir = dir;
	lcon = rcon = idx;
	int rdir = dir;
	//left
	while (true)
	{
		lcon--;
		ldir *= -1;
		if (lcon < 1)
			break;
		if (connect[lcon] == 0)
			break;
		turn(lcon, ldir);
	}
	//right
	while (true)
	{
		if (rcon >= T)
			break;
		if (connect[rcon] == 0)
			break;
		rdir *= -1;
		rcon++;
		turn(rcon, rdir);
	}
}
void getans() {
	for (int i = 1; i <= T; i++) {
		if (tobny[i][0] == 1)
			ans++;
	}
	printf("%d\n", ans);
}
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d",&tobny[i][j]);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int pos, dir;	
		scanf("%d %d", &pos, &dir);
		solve(pos, dir);
	}
	getans();
}