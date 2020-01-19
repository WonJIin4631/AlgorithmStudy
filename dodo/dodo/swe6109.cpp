#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int N;
string s;
int map[21][21];
void solve() {
	vector<int> v;
	queue<int> q;
	if (s == "up") {
		for (int x = 0; x < N; x++) {
			v.clear();
			for (int y = 0; y < N; y++) {
				if (map[y][x] != 0) {
					v.push_back(map[y][x]);
				}
			}
			int idx = 0;
			map[0][x] = v[0];
			for (int j = v.; j < v.size(); j++) {
				if (v[j - 1] == v[j]) {
					map[idx][x] = v[j]*2;
				}
				else {
					map[idx][x] = v[j];
				}
				idx++;
			}
			cout<<"idx" << idx << '\n';
			for (int j = idx; j < N; j++) {
				map[j][x] = 0;
			}
		}
	}
	else if (s == "down") {

	}
	else if (s == "left") {

	}
	else if (s == "right") {

	}
}
int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N>>s;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j] ;
			}
		}
		solve();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout<< map[i][j]<< ' ';
			}
			cout << '\n';
		}
	}
}