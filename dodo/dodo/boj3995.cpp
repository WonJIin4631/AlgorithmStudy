#include<iostream>
using namespace std;

struct ExtendedGcdResult {
	long long s;
	long long t;
	long long r;
};
int N;
int GCD(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
ExtendedGcdResult eGCD(long long a, long long b) {
	long long s0 = 1, t0 = 0, r0 = a;
	long long s1 = 0, t1 = 1, r1 = b;
	long temp;
	while (r1 != 0) {
		long q = r0 / r1;

		temp = r0 - r1* q;
		r0 = r1;
		r1 = temp;

		// 여기까지가 GCD 와 같음 
		temp = s0 - s1*q;
		s0 = s1;
		s1 = temp;

		temp = t0 - t1*q;
		t0 = t1;
		t1 = temp;
	}
	return{ s0,t0,r0 };
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	long long A, B;
	// X : 인당 나눠줄 사탕의 수 
	// Y : 사탕 봉지의 수
	// A * x +1 = B * y
	// Ax +By =C 의 형태로 변환
	// -Ax+By=1
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		ExtendedGcdResult result = eGCD(-A, B);

		// D = gcd(A,B) 일반식 기준
		// Ax +By = C 일때 C % D==0 이어야만 해를 가질 수 있다. : 베주의 항등식
		if (abs(result.r) != 1) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			// x0 = s * C / D;
			// y0 = t * C / D;
			long x = result.s * 1 / result.r;
			long y = result.t * 1 / result.r;

			// x = x0 + B / D *k
			// y = y0 - A / D *k
			while (y <= 0 || x <= 0) {
				x += B;
				y -= -A;
				if (y > 1e9) {
					break;
				}
			}
			if (y > 1e9) {
				cout << "IMPOSSIBLE" << '\n';
			}
			else {
				cout << y << '\n';
			}
		}
	}
	return 0;
}