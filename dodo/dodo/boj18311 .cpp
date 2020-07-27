#include<iostream>
using namespace std;

int dist[100002];
long long halfLine = 0;
int N;
long long K;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> dist[i];
		halfLine += dist[i];
	}
	if (K >= halfLine) {
		K -= halfLine;
		for (int i = N - 1; i >= 0; i--) {
			if (K - dist[i] < 0) {
				cout << i + 1 << '\n';
				break;
			}
			K -= dist[i];
		}
	}
	else {
		for (int i = 0; i <= N; i++) {
			if (K - dist[i] < 0) {
				cout << i + 1 << '\n';
				break;
			}
			K -= dist[i];
		}
	}

	return 0;
}