#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int N, M;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		if (M!=1&&M!=2*N-1)
			cout << '#' << tc << ' ' << 1 << '\n';
		else 
			cout << '#' << tc << ' ' << 0 << '\n';
	}
	return 0;
	/*
	7412653 -> 2
	7413652 -> 3
	*/
}