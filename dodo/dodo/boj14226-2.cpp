#include<iostream>
#include<queue>
using namespace std;

struct Info {
	int cnt;
	int clip;
	int time;
};

int S;
int visit[2000][2000];
int ans;
queue<Info> q;
void solve() {
	q.push({ 1,0,0 });
	visit[1][0] = 1;
	while (!q.empty()){
		Info cur = q.front();
		q.pop();
		if (cur.cnt == S) {
			ans = cur.time;
			break;
		}
		if (cur.cnt > 0 && cur.cnt <= 1001) {
			if (visit[cur.cnt][cur.cnt] == 0) {
				visit[cur.cnt][cur.cnt] = 1;
				q.push({ cur.cnt,cur.cnt,cur.time + 1 });
			}
			if (visit[cur.cnt - 1][cur.clip] == 0) {
				visit[cur.cnt - 1][cur.clip] = 1;
				q.push({ cur.cnt - 1,cur.clip,cur.time + 1 });
			}
		}
		if (cur.clip > 0 && cur.cnt + cur.clip <= 1001) {
			if (visit[cur.cnt + cur.clip][cur.clip] == 0) {
				visit[cur.cnt + cur.clip][cur.clip] = 1;
				q.push({ cur.cnt + cur.clip,cur.clip,cur.time + 1 });
			}
		}
	}
}
int main(){
	cin >> S;
	solve();
	cout << ans << '\n';
	return 0;
}