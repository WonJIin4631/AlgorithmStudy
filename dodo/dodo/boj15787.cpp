#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> Set;
int N, M;

int train[100001][21] = { 0 };
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a ;
		if (a == 1) {
			cin >> b >> c;
			train[b - 1][c - 1] = 1;
		}
		else if (a == 2) {
			cin >> b >> c;
			train[b - 1][c - 1] = 0;
		}
		else if (a == 3) {
			cin >> b;
			for (int j = 19; j > 0; j--) {
				train[b - 1][j] = train[b - 1][j - 1];
			}
			train[b - 1][0] = 0;
		}
		else {
			cin >> b;
			for (int j = 0; j < 19; j++) {
				train[b - 1][j] = train[b - 1][j + 1];
			}
			train[b - 1][19] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		string s;
		for (int j = 0; j < 20; j++) {
			if(train[i][j]==0)
				s.push_back('0');
			else
				s.push_back('1');
		}
		if (Set.find(s) == Set.end()) {
			Set.insert(s);
			ans++;
		}
	}
	cout << ans << '\n';
}