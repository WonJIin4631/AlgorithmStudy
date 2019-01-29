#include<iostream>
#include<queue>
using namespace std;

#define NODE_MAX 1001
int node, line, startnode;
queue<int> qu;
int nodeArr[NODE_MAX][NODE_MAX] = { 0 };
bool DFSvisited[NODE_MAX] = { 0 };
bool BFSvisited[NODE_MAX] = { 0 };
void DFS(int n) {
	DFSvisited[n] = 1;
	cout << n << " ";
	for (int i = 1; i <= node; i++) {
		if (nodeArr[n][i] == 1&& !DFSvisited[i]) {
			DFS(i);
		}
	}
}

void BFS(int n) {
	qu.push(n); BFSvisited[n] = 1;
	while (!qu.empty()) {
		int front = qu.front();
		cout << qu.front() << " ";
		qu.pop();
		for (int i = 1; i <= node; i++) {
			if (nodeArr[front][i] == 1 && !BFSvisited[i]){
				qu.push(i);
				BFSvisited[i] = 1;
			}
		}
	}
}

int main() {

	cin >> node >> line >> startnode;
	for (int i = 0; i < line; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		nodeArr[n1][n2] = 1;
		nodeArr[n2][n1] = 1;
	}
	DFS(startnode);
	cout << "\n";
	BFS(startnode);
}