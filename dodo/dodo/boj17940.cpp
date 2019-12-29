#include<iostream>
#include<queue>

using namespace std;
#define INF 987654321 

typedef pair<int, int> pii;

int N, M, arr[1001], map[1001][1001];
pii d[1001];

struct info {
	int node, trans, dist;
	bool operator < (const info& a) const {
		if (trans == a.trans) {
			return dist > a.dist;
		}
		return trans > a.trans;
	}
};
priority_queue<info> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) 
				map[i][j] = INF;
		}
		d[i] = { INF,INF };
	}
	d[0] = { 0,0 };
	pq.push({ 0,0,0 });
	while (!pq.empty()) {
		info p = pq.top(); 
		pq.pop();
		if (p.node == M) {
			cout << p.trans<< " " << p.dist;
			exit(0);
		}
		for (int i = 0; i <= N; i++) {
			if (map[p.node][i] == INF) continue;
			pii v = { 0,0 };
			if (arr[i] == arr[p.node]) {
				v.first = p.trans;
			}
			else v.first = p.trans+ 1;
			v.second = p.dist + map[p.node][i];
			if (d[i] > v) {
				d[i] = v;
				pq.push({ i,v.first,v.second });
			}
		}
	}
}