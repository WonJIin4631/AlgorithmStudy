#include<iostream>
using namespace std;

#define Max 123456
int num[Max * 2+1];
void getPrimeNumber() {
	for (int i = 2; i <= Max * 2; i++) {
		num[i] = i;
	}
	for (int i = 2; i<= Max * 2; i++) {
		if (num[i] == 0)
			continue;
		for (int j = 2 * i; j <= Max * 2; j += i) {
			num[j] = 0;
		}
	}
}
int main() {
	getPrimeNumber();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true){
		int n;
		cin >> n;
		if (n == 0)
			break;
		int cnt = 0;
		for (int i = n+1; i <= n * 2; i++) {
			if (num[i] == 0)
				continue;
			cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}