#include<iostream>
#include<vector>
#include<queue>
#define MAX_SIZE 100001
using namespace std;
int node_parent[MAX_SIZE] = { 0 };
vector<int> connected_node[MAX_SIZE];

void find() {
	queue<pair<int, int>> qu;

	for (int i = 0; i < connected_node[1].size(); i++) {
		qu.push({ 1, connected_node[1].at(i) });
	}
	while (!qu.empty()) {
		pair<int, int> re = qu.front();
		qu.pop();

		node_parent[re.second] = re.first;
		
		for (int i = 0; i < connected_node[re.second].size(); i++) {
			if (node_parent[connected_node[re.second].at(i)] == 0) {
				qu.push({re.second,connected_node[re.second].at(i) });
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
		connected_node[a].push_back(b);
		connected_node[b].push_back(a);
	}
	node_parent[1] = -1;
	find();

	for (int i = 2; i <= total_node; i++) {
		cout << node_parent[i] << "\n";
	}

	
}