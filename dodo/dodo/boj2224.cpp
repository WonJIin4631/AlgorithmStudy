#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
bool check[58][58];
int ans = 0;
vector<int> list[60];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char n1, n2,t1, t2;
		cin >> n1 >> t1 >> t2 >> n2;
		if (n1 == n2)
			continue;
		check[n1 - 'A'][n2 - 'A'] = true;
	}
	for (int i = 0; i < 58; i++) {
		for (int j = 0; j < 58; j++) {
			for (int k = 0; k < 58; k++) {
				if (check[j][i] && check[i][k]) {
					check[j][k] = true;
				}
			}
		}
	}
	for (int i = 0; i < 58; i++) {
		for (int j = 0; j < 58; j++) {
			if (check[i][j] == true) {
				if (i == j)
					continue;
				ans++;
				list[i].push_back(j);
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < 58; i++) {
		for (int j = 0; j < list[i].size(); j++) {
			char n1 = i + 'A';
			char n2 = list[i][j] + 'A';
			cout << n1 << " => " << n2<<'\n';
		}
	}
	return 0;
}