#include<iostream>
using namespace std;

int N, K;
int ans = 0;
int kits[51];
bool visit[50];
int weight = 500;
void DFS(int cnt) {
	if (cnt == N) {
		ans++;
		return;
	}
	else {
		for (int i = 0; i<N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				if (weight + kits[i] >= 500) {
					weight += kits[i];
					DFS(cnt + 1);
					weight -= kits[i];
					visit[i] = false;
				}
				else
					visit[i] = false;
			}
		}
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> kits[i];
		kits[i] -= K;
	}
	DFS(0);
	cout << ans << '\n';
}