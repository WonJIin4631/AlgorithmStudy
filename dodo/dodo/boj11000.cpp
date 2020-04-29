#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int N;
typedef pair<int, int> pii;
vector<pii> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int st, end;
		cin >> st >> end;
		v.push_back(pii(st,end));
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << '\n';
	return 0;
}