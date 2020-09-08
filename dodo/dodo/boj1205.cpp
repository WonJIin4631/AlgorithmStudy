#include<iostream>

using namespace std;
int main() {
	int n, p;
	int s, s_r = 1, s_p = 1;
	int rank[50 + 1];

	cin >> n >> s >> p;
	for (int i = 0; i < n; i++) {
		cin >> rank[i];
		if (rank[i] > s) s_r++;
		if (rank[i] >= s) s_p++;
	}
	if (s_r > p)
		cout << "-1";
	else if (s_p > p)
		cout << "-1";
	else
		cout << s_r;

	return 0;
}