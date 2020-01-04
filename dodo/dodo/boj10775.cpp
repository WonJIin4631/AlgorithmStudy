#include<iostream>
using namespace std;

int parent[100001];

int find(int n) {
	if (n == parent[n])
		return n;
	else
		return parent[n] = find(parent[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int G, P;
	cin >> G >> P;
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	int gate;
	int ans = 0;
	for (int i = 0; i < P; i++) {
		int n;
		cin >> n;
		gate = find(n);
		if (gate == 0)
			break;
		else {
			ans++;
			merge(gate - 1, gate);
		}
	}
	cout << ans << '\n';
	return 0;
}