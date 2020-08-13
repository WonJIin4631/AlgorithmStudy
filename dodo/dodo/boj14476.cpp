#include<iostream>
using namespace std;
int N;
int numList[1000001];
int gcdLtoR[1000001];
int gcdRtoL[1000001];
int GCD(int a, int b) {
	while (b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int ansgcd = -1;
int ans = -1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numList[i];
	gcdLtoR[0] = numList[0];
	gcdRtoL[N - 1] = numList[N - 1];
	for (int i = 1; i < N; i++) {
		gcdLtoR[i] = GCD(gcdLtoR[i - 1], numList[i]);
		gcdRtoL[N - 1 - i] = GCD(gcdRtoL[N - i], numList[N - 1 - i]);
	}
	for (int i = 0; i < N; i++) {
		int left = i - 1;
		int right = i + 1;
		int val;
		if (left < 0) {
			val = gcdRtoL[right];
		}
		else if (right == N) {
			val = gcdLtoR[left];
		}
		else {
			val = GCD(gcdLtoR[left], gcdRtoL[right]);
		}
		if (ansgcd < val) {
			if (numList[i] % val != 0) {
				ansgcd = val;
				ans = numList[i];
			}
		}
	}
	if (ansgcd == -1)
		cout << -1 << '\n';
	else
		cout << ansgcd << ' ' << ans << '\n';
	return 0;
}