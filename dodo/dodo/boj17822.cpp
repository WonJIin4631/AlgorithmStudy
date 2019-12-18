#include<iostream>
#include<deque>
#include<queue>
#include<string.h>
using namespace std;
int N, M, T;
int pan[52][51];
int visit[52][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int ans = 0;

void change() {
	double sum = 0;
	double cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (pan[i][j] != 0) {
				sum += pan[i][j];
				cnt++;
			}
		}
	}
	double avg = sum / cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (pan[i][j] != 0) {
				if (pan[i][j] > avg)
					pan[i][j] -= 1;
				else if (pan[i][j] < avg)
					pan[i][j] += 1;
			}
		}
	}
}
bool BFS(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	int cnt = 0;
	int val = pan[y][x];
	while (!q.empty()) {
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx == -1)
				nx = M - 1;
			if (nx == M)
				nx = 0;
			if (nx >= 0 && nx < M&&ny >= 1 && ny <= N) {
				if (visit[ny][nx] == 0 && pan[ny][nx] == val) {
					q.push(make_pair(ny, nx));
					visit[ny][nx] = 1;
					pan[ny][nx] = 0;
					cnt++;
				}
			}
		}
	}
	if (cnt == 0) {
		return false;
	}
	else {
		pan[y][x] = 0;
		return true;
	}
}
void check_same() {
	bool flag = true;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0 && pan[i][j] != 0) {
				if (BFS(i, j))
					flag = false;
			}
		}
	}
	if (flag)
		change();
}
void move_pan(int a, int b, int c) {
	deque<int> dq;
	for (int i = a; i <= N; i++) {
		if ((i % a) == 0) {
			for (int j = 0; j < M; j++) {
				dq.push_back(pan[i][j]);
			}
			if (b == 0) {
				for (int k = 0; k < c; k++) {
					int temp = dq.back();
					dq.pop_back();
					dq.push_front(temp);
				}
			}
			else if (b == 1) {
				for (int k = 0; k < c; k++) {
					int temp = dq.front();
					dq.pop_front();
					dq.push_back(temp);
				}
			}
			for (int j = 0; j < M; j++) {
				pan[i][j] = dq.front();
				dq.pop_front();
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		move_pan(x, d, k);
		check_same();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			ans += pan[i][j];
		}
	}
	cout << ans << '\n';
}