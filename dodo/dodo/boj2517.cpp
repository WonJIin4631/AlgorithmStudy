#include<iostream>
using namespace std;

struct Info {
	int pos;
	int power;
};
Info runner[500005];
Info temp[500005];
int ans[500005];
void merge(int s, int m, int e) {
	int p1 = s;
	int p2 = m;
	int k = s;
	while (p1 < m&&p2 < e) {
		if (runner[p1].power <= runner[p2].power) {
			temp[k++] = runner[p1++];
		}
		else {
			int advance = p1 - s;
			int origin_rank = runner[p2].pos;
			if (advance) {
				ans[origin_rank] -= advance;
			}
			temp[k++] = runner[p2++];
		}
	}
	
	while (p1 < m) {
		temp[k++] = runner[p1++];
	}
	
	while (p2 < e) {
		int advance = p1 - s;
		int origin_rank = runner[p2].pos;
		if (advance) {
			ans[origin_rank] -= advance;
		}
		temp[k++] = runner[p2++];
	}

	for (int i = s; i < e; i++)
		runner[i] = temp[i];
}
void merge_sort(int s, int e) {
	int m = (s + e) / 2;
	if (s < m) {
		merge_sort(s, m);
		merge_sort(m, e);
		merge(s, m, e);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> runner[i].power;
		runner[i].pos = i;
		ans[i] = i;
	}
	merge_sort(1, N + 1);
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}