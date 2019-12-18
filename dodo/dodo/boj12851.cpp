#include<iostream>
#include<queue>
using namespace std;

int map[100001];
int visit[100001];
queue<int> q;
int N, K, time;
int min_time = 987654321;
int cnt = 0;

void BFS() {

	int size;

	while (!q.empty()) {
		size = q.size();
		for (int i = 0; i < size; i++) {
			int cur = q.front();
			visit[cur] = 1;
			q.pop();
			if (cur == K) {
				if (time <= min_time) {
					min_time = time;
					cnt++;
				}
				else return;
			}
			int next = cur - 1;
			if (0 <= next && visit[next] == 0) {
				q.push(next);
			}

			next = cur + 1;
			if (next <= 100000 && visit[next] == 0) {
				q.push(next);
			}

			next = cur * 2;
			if (next <= 100000 && visit[next] == 0) {
				q.push(next);
			}
		}
		time++;
	}
}
int main() {
	cin >> N >> K;

	visit[N] = 1;
	q.push(N);
	BFS();
	
	cout << min_time << '\n'<< cnt << '\n';
}