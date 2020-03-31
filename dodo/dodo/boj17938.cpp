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
	int turn = 1;
	int st_p = 0;
	int end_p = 0;
	int curHand = 0;

	int state = 1;
	cin >> N >> P >> T;
	while (true) {
		curHand += state;
		st_p = end_p;
		end_p += curHand;
		//T차례일때 확인
		if (end_p > 2 * N)
			end_p -= (2 * N);
		if (turn == T) {
			st_p = (st_p + 1) / 2;
			end_p = (end_p + 1) / 2;
			if (st_p <= end_p) {
				if (st_p < P && P <= end_p) {
					cout << "Dehet YeonJwaJe ^~^" << '\n';
					break;
				}
			}
			else {
				if (st_p < P || end_p >= P) {
					cout << "Dehet YeonJwaJe ^~^" << '\n';
					break;
				}
			}
			cout << "Hing…NoJam" << '\n';
			break;
		}
		if (curHand == 2 * N || (turn != 1 && curHand == 1))
			state *= -1;
		turn++;
	}
}