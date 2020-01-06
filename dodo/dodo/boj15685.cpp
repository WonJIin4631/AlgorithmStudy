#include<iostream>
#include<vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int ans = 0;
int map[101][101] = { 0 };
int N;
int change(int d) {
	if (d == 0)
		return 1;
	else if (d == 1)
		return 2;
	else if (d == 2)
		return 3;
	else
		return 0;
}
void curve(int x, int y, int d, int g) {
	vector<int> v;
	v.push_back(d);
	while (g > 0) {
		int s = v.size();
		for (int i = s - 1; i >= 0; i--) {
			int dir = v[i];
			v.push_back(change(dir));
		}
		g--;
	}
	map[y][x] = 1;
	for (int i = 0; i < v.size(); i++) {
		int nx = x + dx[v[i]];
		int ny = y + dy[v[i]];
		if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100) {
			map[ny][nx] = 1;
			y = ny;
			x = nx;
		}
	}
}
void count() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				ans++;
		}
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		curve(x, y, d, g);
	}
	count();
	cout << ans << "\n";
	return 0;
}