#include<iostream>
using namespace std;

int N, P, T;
int main() {
	int t = 1;
	int s = 0, e = 0;
	int cnt = 0;
	cin >> N >> P >> T;
	for (int i = 1; i <= T; i++) {
		cnt += t;
		s = e;
		e += cnt;
		if (cnt == 2 * N || (cnt == 1 && i != 1)) {
			t = -t;
		}
		if (e > 2 * N)
			e -= 2 * N;
	}
	s = (s + 1) / 2;
	e = (e + 1) / 2;
	if (s > e) {
		if (P > s || P <= e)
			cout << "Dehet YeonJwaJe ^~^" << '\n';
		else
			cout << "Hing...NoJam" << '\n';
	}
	else {
		if (s < P && P <= e)
			cout << "Dehet YeonJwaJe ^~^" << '\n';
		else
			cout << "Hing...NoJam" << '\n';
	}
	return 0;
}