#include<iostream>
#include<queue>
using namespace std;

int K;
int W, H;
int map[201][201];
bool visit[32][201][201] = { false };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int tx[] = { -2,-1,1,2,-2,-1,1,2 };
int ty[] = { 1,2,2,1,-1,-2,-2,-1 };
typedef pair<int, int> pii;
int ans = -1;
void solve() {

	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	visit[0][0][0] = 1;
	while (!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int jump= q.front().second.first;
		int time = q.front().second.second;
		q.pop();
		if (y == H - 1 && x == W - 1) {
			ans = time;
			return;
		}
		if (jump < K){
			for (int i = 0; i < 8; i++){
				int ny = y + ty[i];
				int nx = x+ tx[i];
				if (0 <= ny && ny < H && 0 <= nx && nx < W)
					if (!visit[jump+1][ny][nx] && map[ny][nx]==0){
						visit[jump + 1][ny][nx] = true;
						q.push(make_pair(make_pair(ny, nx), make_pair(jump + 1, time + 1)));
					}
			}
		}
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < H && 0 <= nx && nx < W)
				if (!visit[jump][ny][nx] && map[ny][nx] == 0){
					visit[jump][ny][nx] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(jump, time + 1)));
				}
		}
	}
}	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}