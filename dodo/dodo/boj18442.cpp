#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int V, P;
long long L;
long long cityPos[21];
int visit[21] = { 0 };
long long ans_val = LLONG_MAX;
int ans[21] = { 0 };
void DFS(int cnt, int idx) {
	if (cnt == P) {
		long long temp = 0;
		for (int i = 0; i < V; i++) {
			if (visit[i] == 1)
				continue;
			long long cmpd = LLONG_MAX;
			long long d;
			for (int j = 0; j < V; j++) {
				if (j != i&&visit[j] == 1) {
					d = abs(cityPos[j] - cityPos[i]);
					if (cmpd > min(d, L - d)) {
						cmpd = min(d, L - d);
					}
				}
			}
			temp += cmpd;
		}
		if (temp < ans_val) {
			for (int i = 0; i < V; i++) {
				ans[i] = visit[i];	
			}
			ans_val = temp;
		}
		return;
	}
	for (int i = idx; i < V; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			DFS(cnt + 1, i + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> V >> P >> L;
	for (int i = 0; i < V; i++) {
		cin >> cityPos[i];
	}
	DFS(0, 0);
	cout << ans_val << '\n';
	for (int i = 0; i < V; i++) {
		if (ans[i] == 1)
			cout << cityPos[i] << ' ';
	}
	return 0;
}