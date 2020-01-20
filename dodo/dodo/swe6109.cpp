#include<iostream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;
int N;
string s;
int map[22][22];
void solve() {
	stack<int> st;
	if (s == "up") {
		for (int x = 0; x < N; x++) {	
			for (int y = N - 1; y >= 0; y--) {
				if (map[y][x] != 0) {
					st.push(map[y][x]);
				}
			};	
			int idx = 0;
			while (!st.empty()){
				int temp = st.top();
				st.pop();
				if (st.empty()) {
					map[idx++][x] = temp;
					break;
				}
				if (temp == st.top()) {
					map[idx++][x] = temp * 2;
					st.pop();
				}
				else {
					map[idx++][x] = temp;
				}
			}
			for (int i = idx; i < N; i++) {
				map[i][x] = 0;
			}
		}
	}
	else if (s == "down") {
		for (int x = 0; x < N; x++) {
			for (int y =0; y < N; y++) {
				if (map[y][x] != 0) {
					st.push(map[y][x]);
				}
			};
			int idx = N-1;
			while (!st.empty()) {
				int temp = st.top();
				st.pop();
				if (st.empty()) {
					map[idx--][x] = temp;
					break;
				}
				if (temp == st.top()) {
					map[idx--][x] = temp * 2;
					st.pop();
				}
				else {
					map[idx--][x] = temp;
				}
			}
			for (int i = idx; i >= 0; i--) {
				map[i][x] = 0;
			}
		}
	}
	else if (s == "left") {
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x >= 0; x--) {
				if (map[y][x] != 0) {
					st.push(map[y][x]);
				}
			};
			int idx = 0;
			while (!st.empty()) {
				int temp = st.top();
				st.pop();
				if (st.empty()) {
					map[y][idx++] = temp;
					break;
				}
				if (temp == st.top()) {
					map[y][idx++] = temp * 2;
					st.pop();
				}
				else {
					map[y][idx++] = temp;
				}
			}
			for (int i = idx; i < N; i++) {
				map[y][i] = 0;
			}
		}
	}
	else if (s == "right") {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] != 0) {
					st.push(map[y][x]);
				}
			};
			int idx = N-1;
			while (!st.empty()) {
				int temp = st.top();
				st.pop();
				if (st.empty()) {
					map[y][idx--] = temp;
					break;
				}
				if (temp == st.top()) {
					map[y][idx--] = temp * 2;
					st.pop();
				}
				else {
					map[y][idx--] = temp;
				}
			}
			for (int i = idx; i >= 0; i--) {
				map[y][i] = 0;
			}
		}
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
		cout << '#' << tc << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout<< map[i][j]<< ' ';
			}
			cout << '\n';
		}
	}
}