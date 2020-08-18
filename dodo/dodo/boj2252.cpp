#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int in[32004] = { 0 };
vector<int> node[32004];
queue<int> q;
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		in[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0)
			q.push(i);
	}
	while (q.size()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < node[cur].size(); i++) {
			in[node[cur][i]]--;
			if (!in[node[cur][i]])
				q.push(node[cur][i]);
		}
	}
	return 0;
}