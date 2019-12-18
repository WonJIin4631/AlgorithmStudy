#include<iostream>
#include<queue>
using namespace std;

int subin, dongseng;
int ans = 987654321;

int visit[100001];
void solve() {
	queue<int> q;
	q.push(subin);
	visit[subin] = 1;
	int t = 0;
	while (!q.empty()){
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int pos = q.front();
			q.pop();
			if (pos == dongseng) {
				if (ans > t)
					ans = t;
			}
			if (pos * 2 <= 100000 && visit[pos * 2] == 0) {
				q.push(pos * 2);
				visit[pos * 2] = 1;
			}
			if (pos - 1 >= 0 && visit[pos - 1] == 0) {
				q.push(pos - 1);
				visit[pos - 1] = 1;
			}
			if (pos + 1 <= 100000 && visit[pos + 1] == 0) {
				q.push(pos + 1);
				visit[pos + 1] = 1;
			}
		}
		t++;
	}
}

int main() {
	cin >> subin >> dongseng;
	solve();
	cout << ans << '\n';
}