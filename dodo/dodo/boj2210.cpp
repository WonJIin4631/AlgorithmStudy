#include<iostream>
#include<set>
#include<string>
using namespace std;

char map[5][5];
set<string> Set;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool isIn(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}
void sovle(string s, int cnt,int x,int y) {
	if (cnt == 6) {
		if (Set.find(s) == Set.end()) {
			Set.insert(s);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isIn(nx, ny)) {
			s += map[ny][nx];
			sovle(s, cnt + 1, nx, ny);
			s.pop_back();
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			string s = "";
			s+=map[i][j];
			sovle(s, 1, j, i);
			s.pop_back();
				
		}
	}
	cout << Set.size() << '\n';
	return 0;
}