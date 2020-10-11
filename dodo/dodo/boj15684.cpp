#include<iostream>
#include<algorithm>
using namespace std;

int N, H, M;
int line[11][31] = { 0 };

int ans = 4;
bool flag = false;
bool move_line() {
	bool check = true;
	for (int i = 1; i <= N; i++) {
		int temp = i;
		for (int j = 1; j <= H; j++) {
			if (line[temp][j] == 1) {
				temp++;
			}
			else if ((temp - 1 > 0) && (line[temp - 1][j]==1)) {
				temp--;
			}
		}
		if (temp != i) {
			check = false;
			break;
		}
	}
	return check;
}
void DFS(int h, int cnt) {
	if (cnt <= 3) {
		if (move_line()) {
			ans = min(cnt, ans);
			return;
		}
	}
	else
		return;
	for (int i = h; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (line[j][i] == 0) {
				if (line[j - 1][i] == 0 & line[j + 1][i] == 0) {
					line[j][i] = 1;
					DFS(i, cnt + 1);
					line[j][i] = 0;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		line[b][a] = 1;
	}
	DFS(1, 0);
	if (ans == 4)
		ans = -1;
	cout << ans << '\n';
	return 0;
}