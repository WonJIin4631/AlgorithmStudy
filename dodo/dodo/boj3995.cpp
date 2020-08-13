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

		// ��������� GCD �� ���� 
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
	// X : �δ� ������ ������ �� 
	// Y : ���� ������ ��
	// A * x +1 = B * y
	// Ax +By =C �� ���·� ��ȯ
	// -Ax+By=1
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		ExtendedGcdResult result = eGCD(-A, B);

		// D = gcd(A,B) �Ϲݽ� ����
		// Ax +By = C �϶� C % D==0 �̾�߸� �ظ� ���� �� �ִ�. : ������ �׵��
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