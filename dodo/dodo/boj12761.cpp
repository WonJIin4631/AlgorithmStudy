#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

struct Info{
	int pos;
	int cnt;
};
int check[100001];
queue<Info> q;
int A, B, N, M;
int ans = 987654321;
int dir[] = { -1,1 };
bool Isin(int pos) {
	return pos >= 0 && pos <= 100000;
}
int main() {
	cin >> A >> B >> N >> M;
	memset(check, 0x3f3f3f3f, sizeof(check));
	q.push({ N,0 });

	while (!q.empty()){
		Info cur = q.front();
		q.pop();
		bool flag = false;
		for (int i = 0; i < 2; i++) {
			int nPos = cur.pos + dir[i];
			if (nPos == M) {
				ans = cur.cnt + 1;
				flag = true;
				break;
			}
			if (Isin(nPos)) {
				if (check[nPos] > cur.cnt + 1) {
					check[nPos] = cur.cnt + 1;
					q.push({ nPos,cur.cnt + 1 });
				}
			}
			nPos = cur.pos + dir[i] * A;
			if (nPos == M) {
				ans = cur.cnt + 1;
				flag = true;
				break;
			}
			if (Isin(nPos)) {
				if (check[nPos] > cur.cnt + 1) {
					check[nPos] = cur.cnt + 1;
					q.push({ nPos,cur.cnt + 1 });
				}
			}
			nPos = cur.pos + dir[i] * B;
			if (nPos == M) {
				ans = cur.cnt + 1;
				flag = true;
				break;
			}
			if (Isin(nPos)) {
				if (check[nPos] > cur.cnt + 1) {
					check[nPos] = cur.cnt + 1;
					q.push({ nPos,cur.cnt + 1 });
				}
			}
			nPos = cur.pos * dir[i] * A;
			if (nPos == M) {
				ans = cur.cnt + 1;
				flag = true;
				break;
			}
			if (Isin(nPos)) {
				if (check[nPos] > cur.cnt + 1) {
					check[nPos] = cur.cnt + 1;
					q.push({ nPos,cur.cnt + 1 });
				}
			}
			nPos = cur.pos * dir[i] * B;
			if (nPos == M) {
				ans = cur.cnt + 1;
				flag = true;
				break;
			}
			if (Isin(nPos)) {
				if (check[nPos] > cur.cnt + 1) {
					check[nPos] = cur.cnt + 1;
					q.push({ nPos,cur.cnt + 1 });
				}
			}
		}
		if (flag)
			break;
	}
	cout << ans << '\n';
	return 0;
}