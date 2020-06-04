#include<iostream>
using namespace std;

struct Pos {
	int x;
	int y;
	int time;
};
struct Info {
	int st;
	int l;
	int r;
};
char map[21][21];
bool visit[21][21];
int N, M;
int ans;
int sinho;
Info hoho[10];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= '0'&&map[i][j] <= '9') {
				sinho++;
			}
		}
	}
	if (sinho > 0) {
		int n, l, r;
		char c;
		for (int i = 0; i < sinho; i++) {
			cin >> n >> c >> l >> r;

		}
	}
}
void solve() {
	while (true){
		ans = 987654321;
		sinho = 0;
		cin >> N >> M;
	}
}
int main() {
	return 0;
}