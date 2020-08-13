#include<iostream>
using namespace std;

int GCD(int a, int b) {
	while (b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	int A1, B1, A2, B2;
	int ansA, ansB;
	cin >> A1 >> B1 >> A2 >> B2;
	ansA = (A1*B2) + (A2*B1);
	ansB = B1*B2;
	int temp = GCD(ansA, ansB);
	cout << ansA/temp << ' ' << ansB/temp << '\n';
	return 0;
}