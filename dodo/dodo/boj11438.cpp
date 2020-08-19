#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100005

int n, m, d;
vector<int> node[MAX];
int dept[MAX], parent[MAX][17];
void dfs(int now, int cnt) {
	dept[now] = cnt++;
	for (int i = 1; i <= d; i++)
		parent[now][i] = parent[parent[now][i - 1]][i - 1];
	for (auto val : node[now]) {
		if (!dept[val]) {
			parent[val][0] = now;
			dfs(val, cnt);
		}
	}
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (d = 1; (1 << d) <= n; d++);
	d--;
	cout << d << '\n';
	while (--n) {
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &a, &b);
		if (dept[a] < dept[b])
			swap(a, b);
		for (i = d; i >= 0; i--)
			if (dept[b] <= dept[parent[a][i]])
				a = parent[a][i];
		if (a == b) {
			printf("%d\n", a);
			continue;
		}
		for (i = d; i >= 0; i--)
			if (parent[a][i] != parent[b][i])
				a = parent[a][i], b = parent[b][i];
		printf("%d\n", parent[a][0]);
	}
	return 0;
}