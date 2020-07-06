#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
struct Info{
	int n;
	int idx;
	int val;
};
struct CompByNum{
	bool operator ()(Info a, Info b) {
		return a.n < b.n;
	}
};
struct CompByIdx{
	bool operator ()(Info a, Info b) {
		return a.idx < b.idx;
	}
};
vector<Info> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		v.push_back({ n,i,0 });
	}
	sort(v.begin(), v.end(), CompByNum());
	for (int i = 1; i < N; i++) {
		if (v[i - 1].n == v[i].n) {
			v[i].val = v[i-1].val;
		}
		else {
			v[i].val = v[i - 1].val +1;
		}
	}
	sort(v.begin(), v.end(), CompByIdx());
	for (int i = 0; i < N; i++) {
		cout << v[i].val << ' ';
	}

	return 0;
}