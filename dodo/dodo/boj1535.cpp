#include<iostream>
#include<algorithm>
using namespace std;

struct info {
	int L;
	int J;
};

bool comp(info a, info b) {
	return a.L < b.L;
}


int N;
info arr[21];
int visit[21] = { 0 };
int ans = 0;

void solve(int health, int happy, int idx) {
	if (health <= 0) {
		return;
	}
	ans = max(ans, happy);
	for (int i = idx; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			solve(health - arr[i].L, happy + arr[i].J, i);
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].L;
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i].J;
	}
	sort(arr, arr + N, comp);
	solve(100, 0, 0);
	cout << ans << '\n';
	return 0;
}