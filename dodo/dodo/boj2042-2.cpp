	#include<iostream>
	#include<algorithm>
	#define MAX 1000001
	using namespace std;

	long long num[MAX];
	long long tree[(MAX * 4)];
	int N, M, K;

	long long init(int start, int end, int node) {
		if (start == end)
			return tree[node] = num[start];
		int mid = (start + end) / 2;
		return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
	}

	long long query(int start, int end, int node, int left, int right) {
		if (end < left || start > right)
			return 0;
		if (left <= start&&end <= right)
			return tree[node];
		int mid = (start + end) / 2;
		return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2+1, left, right);
	}
	void update(int start, int end, int node, int index, int diff) {
		if (index < start || end < index)
			return;
		tree[node] += diff;
		if (start == end)
			return;
		int mid = (start + end) / 2;
		update(start, mid, node * 2, index, diff);
		update(mid + 1, end, node * 2 + 1, index, diff);
	}
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		init(0, N - 1, 1);
		int a;
		for (int i = 0; i < M + K; i++) {
			cin >> a;
			if (a == 2) {
				int b, c;
				cin >> b >> c;
				if (b > c)
					swap(b, c);
				cout << query(0, N - 1, 1, b-1, c-1)<<'\n';
			}
			else {
				int b;
				long long c;
				cin >> b >> c;
				long long dif = c - num[b - 1];
				num[b - 1] = c;
				update(0, N - 1, 1, b-1, dif);
			}
		}
		return 0;
	}