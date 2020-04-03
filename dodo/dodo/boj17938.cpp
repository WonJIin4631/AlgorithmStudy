#include<iostream>
using namespace std;
/*
시작 0 마지막 (2*N)-1
팔의 개수는 최대 2N개
1개씩 증가 했다 2N개가 되면 1개씩 감소

*/
int main() {
	int N;
	int P, T;
	int t = 1;
	int st = 0;
	int end = 0;
	int cnt = 0;
	cin >> N >> P >> T;
	for (int i = 1; i< T + 1; i++) {
		cnt += t;
		st = end;
		end += cnt;
		if (cnt == 2 * N || (cnt == 1 && i != 1)) {
			t = -t;
		}
		if (end > 2 * N)
			end -= 2 * N;
	}
	st = (st + 1) / 2;
	end = (end + 1) / 2;
	if (st > end) {
		if (P > st || P <= end)
			cout << "Dehet YeonJwaJe ^~^" << '\n';
		else
			cout << "Hing...NoJam" << '\n';
	}
	else {
		if(st < P && P <= end)
			cout << "Dehet YeonJwaJe ^~^" << '\n';
		else
			cout << "Hing...NoJam" << '\n';
	}
}