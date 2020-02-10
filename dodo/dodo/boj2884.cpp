#include<iostream>
using namespace std;


/*
45분일찍 알람맞추기 -> 원래알람에서 45분 빠르게 맞추면됨
하루시작 0:0 하루 끝 23:59
알람 맞춘시간이 이 45분이하이면 ->시간 -1 분 +60;
만약 시간이 0:에서 -1시간하게되면 23으로 해야됨


*/
int st_h, st_m;
int ans_h, ans_m;
int main() {
	cin >> st_h >> st_m;
	if (st_m >= 45) {
		ans_h = st_h;
		ans_m = st_m - 45;
	}
	else {
		if (st_h == 0) {
			ans_h = 23;
			ans_m = st_m + 60 - 45;
		}
		else {
			ans_h = st_h - 1;
			ans_m = st_m + 60 - 45;
		}
	}
	cout << ans_h << ' ' << ans_m << '\n';
	return 0;
}