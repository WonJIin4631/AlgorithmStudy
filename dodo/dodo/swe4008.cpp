#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int ans = 0;
int opCard[4];
int minVal;
int maxVal;
int op_cnt = 0;
int numCard[13];
int N;
void DFS(int idx, int cur) {
	if (idx == N-1) {
		minVal = min(cur, minVal);
		maxVal = max(cur, maxVal);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (opCard[i] != 0) {
			if (i == 0) {
				opCard[i]-=1;
				DFS(idx + 1, cur + numCard[idx + 1]);
				opCard[i] += 1;
			}
			else if (i == 1) {
				opCard[i] -= 1;
				DFS(idx + 1, cur - numCard[idx + 1]);
				opCard[i] += 1;
			}
			else if (i == 2) {
				opCard[i] -= 1;
				DFS(idx + 1, cur * numCard[idx + 1]);
				opCard[i] += 1;
			}
			else {
				opCard[i] -= 1;
				DFS(idx + 1, cur / numCard[idx + 1]);
				opCard[i] += 1;
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		//memset(opCard, 0, sizeof(opCard));
		minVal = 1e9;
		maxVal = -1e9;
		cin >> N;
		for (int i = 0; i < 4; i++) {
			cin >> opCard[i];
			op_cnt += opCard[i];
		}
		for (int i = 0; i < N;i++) {
			cin >> numCard[i];
		}
		DFS(0, numCard[0]);

		ans = maxVal - minVal;
		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}