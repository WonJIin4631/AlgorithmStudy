#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct Info{
	int num;
	int idx;
};
int T, N, M;
int check[10] = { 0 };
queue<Info> q;
int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int cnt = 0;
		int maxNum = 0;
		memset(check, 0, sizeof(check));
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			check[n]++;
			maxNum = max(n, maxNum);
			q.push({ n,i });
		}
		bool flag = false;
		while (!q.empty()) {
			Info cur = q.front();
			q.pop();
			if (flag)
				continue;
			if (cur.num < maxNum) {
				q.push(cur);
			}
			else if (cur.num == maxNum) {
				cnt++;
				if (cur.idx == M) {
					flag = true;
					cout << cnt << '\n';
				}
				check[cur.num]--;
				while (true){
					if (check[maxNum] != 0)
						break;
					maxNum--;
				}
			}
		}
	}
	return 0;
}