#include<iostream>
#include<vector>
#include<queue>
#define MAX_SIZE 100001
using namespace std;
int node_parent[MAX_SIZE] = { 0 };
vector<int> v[MAX_SIZE];

void find() {
	queue<pair<int, int>> q;

	for (int i = 0; i < v[1].size(); i++) {
		q.push({ 1, v[1].at(i) });
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		node_parent[cur.second] = cur.first;

		for (int i = 0; i < v[cur.second].size(); i++) {
			if (node_parent[v[cur.second].at(i)] == 0) {
				q.push({ cur.second,v[cur.second].at(i) });
			}
		}
	}
}
int main() {

	int total_node;
	cin >> total_node;
	for (int i = 0; i < total_node - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	node_parent[1] = -1;
	find();

	for (int i = 2; i <= total_node; i++) {
		cout << node_parent[i] << '\n';
	}
	return 0;

}