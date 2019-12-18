#include<iostream>
#include<vector>
using namespace std;


/*
4개 말 10개 주사위 수
말이 이동 멈출때 위치 점수 추가
같은자리에 이동 불가
종료위치 이상 갈때 종료위치
종료위치 말 이동 안됨
*/


int move_list[11];
int map[] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0/*여기까지21*/,10,13,16,19,25/*오른쪽 26*/,20,22,24,25,30,35,40/*위로 33*/,30,28,27,26,25 /*왼쪽 38*/};
int mal[5] = { 0 };
int summal[5] = { 0 };
int visit[47];
bool fin[5] = { false };
int ans = 0;
int change(int cur,int num) {

	int n_pos =num + cur;
	if (cur >= 0 && cur <= 20) {
		if (n_pos == 5)
			return 22;
		if (n_pos == 10)
			return 27;
		if (n_pos == 15)
			return 34;
		if (n_pos > 20)
			return 21;
	}
	else if (cur >= 22 && cur <= 26) {
		if (n_pos >= 30)
			return 21;
		if (n_pos == 29)
			return 20;
		else if (n_pos == 26)
			return 30;
		else if (n_pos > 26)
			return 30 - (26 - cur) + num;
	}
	else if (cur >= 27 && cur <= 33) {
		if (n_pos == 33)
			return 20;
		if (n_pos > 33)
			return 21;
	}
	else if (cur >= 34 && cur <= 38) {
		if (n_pos >= 42)
			return 21;
		if (n_pos == 41)
			return 20;
		else if (n_pos == 38)
			return 30;
		else if(n_pos>38)
			return 30 - (38 - cur) + num;
	}
	return n_pos;
}
void solve(int cnt,int sum) {
	if (cnt == 10) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		//종료 위치에 있는말 이동안함
		if (mal[i] == 21)
			continue;
		int curpos = mal[i];
		int nextpos = change(curpos, move_list[cnt]);
		//다음 자리에 말이 위치하면 안움직임
		if (visit[nextpos] == 1)
			continue;
		//말이 종료시에
		if (nextpos == 21) {
			visit[curpos] = 0;
			mal[i] = nextpos;
			solve(cnt + 1, sum);
			mal[i] = curpos;
			visit[curpos] = 1;
		}
		//아닐시
		else {
			visit[curpos] = 0;
			visit[nextpos] = 1;
			mal[i] = nextpos;
			solve(cnt + 1, sum+map[mal[i]]);
			mal[i] = curpos;
			visit[curpos] = 1;
			visit[nextpos] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> move_list[i];
	}
	solve(0,0);
	cout << ans << '\n';
}