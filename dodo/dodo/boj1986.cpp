#include<iostream>
#include<vector>
using namespace std;

struct Info {
	int x;
	int y;
};
vector<Info> Knight;
vector<Info> Queen;
int N, M;
bool map[1002][1002] = { 0 };
bool check[1002][1002] = { 0 };
int Qdx[] = { -1,0,1,-1,1,-1,0,1 };
int Qdy[] = { -1,-1,-1,0,0,1,1,1 };
int Kdx[] = { 1,2,2,1,-1,-2,-2,-1 };
int Kdy[] = { -2,-1,1,2,2,1,-1,-2 };
bool Isin(int x, int y) {
	return x >= 1 && x <= M&&y >= 1 && y <= N;
}
void init() {
	cin >> N >>M;
	int n;
	int x; int y;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		map[y][x] = true;
		Queen.push_back({ x,y });
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		map[y][x] = true;
		Knight.push_back({ x,y });
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		map[y][x] = true;
	}
}
void move_Mal() {
	for (int i = 0; i < Queen.size(); i++) {
		for (int d = 0; d < 8; d++) {
			int x = Queen[i].x;
			int y = Queen[i].y;
			while (true) {
				x += Qdx[d];
				y += Qdy[d];
				if (!Isin(x, y))
					break;
				if (map[y][x] == true)
					break;
				check[y][x] = true;
			}
		}
	}
	for (int i = 0; i < Knight.size(); i++) {
		for (int d = 0; d < 8; d++) {
			int x = Knight[i].x + Kdx[d];
			int y = Knight[i].y + Kdy[d];
			if (Isin(x, y)) {
				check[y][x] = true;
			}
		}
	}

}
void solve() {
	move_Mal();
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == false) {
				if (check[i][j] == false) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	solve();

	return 0;
}