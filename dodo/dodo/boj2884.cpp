#include<iostream>
using namespace std;


/*
45������ �˶����߱� -> �����˶����� 45�� ������ ���߸��
�Ϸ���� 0:0 �Ϸ� �� 23:59
�˶� ����ð��� �� 45�������̸� ->�ð� -1 �� +60;
���� �ð��� 0:���� -1�ð��ϰԵǸ� 23���� �ؾߵ�


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