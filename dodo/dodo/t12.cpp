#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> tree;

void find() {
	int left = 1; int right = tree.at(N-1);
	while (left <= right) {
		int total = 0;
		int mid = (right + left) / 2;

		for (int i = 0; i < N && total<=M ; i++) {
			if (tree.at(i) > mid)
				total += tree.at(i) - mid;
		}
		if (total == M) {
			cout << mid << endl;
			return;
		}
		else if (total - M > 0)
			left=mid+1;		
		else 
			right=mid-1;
	}
	cout << right << endl;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		tree.push_back(num);
	}
	sort(tree.begin(), tree.end());
	find();
}