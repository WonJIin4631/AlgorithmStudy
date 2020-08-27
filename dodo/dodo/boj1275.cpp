#include<iostream>
#include<vector>
#define MAX 100001
using namespace std;

long long num[MAX];
long long tree[(MAX * 10)];
int N, Q;
long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = num[start];

	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start&&end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(int start, int end, int node, int index, long long dif) {
	if (index<start || index>end)
		return;
	tree[node] += dif;

	if (start == end)
		return;
	int mid = (start + end) / 2;

	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	init(0, N - 1, 1);
	int x, y, a;
	long long b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x > y) {
			int temp = y;
			y = x;
			x = temp;
		}
		long long dif = b - num[a-1];
		cout << sum(0, N - 1, 1, x-1, y-1) << '\n';
		num[a - 1] = b;
		update(0, N - 1, 1, a-1, dif);
	}
	return 0;
}