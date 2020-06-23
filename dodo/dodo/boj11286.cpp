#include<iostream>
#include<queue>
using namespace std;

struct Info{
	int num;
	int abs;
};
struct comp{
	bool operator()(Info &a, Info &b) {
		if (a.abs == b.abs)
			return a.num > b.num;
		return a.abs > b.abs;
	}
};
priority_queue<Info, vector<Info>, comp> pq;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			if (pq.size() == 0) {
				cout<< 0 << '\n';
			}
			else {
				cout<<pq.top().num << '\n';
				pq.pop();
			}
		}
		else {
			int t=n;
			if (n < 0)
				t *= -1;
			pq.push({ n,t });
		}
	}
	return 0;
}