#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define MAX_CANDY 1000000

typedef long long ll;
int K;
int tree_size;
int ret;


void update(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

ll query(vector<ll> &tree, int node, int start, int end, int k){
	if ((start == end) && ret == 0)	{
		cout << start << '\n';
		return start;
	}

	if (ret == 0 && (node * 2 <= tree_size && tree[node * 2] >= k))
		return ret = query(tree, node * 2, start, (start + end) / 2, k);

	k -= tree[node * 2];

	if (ret == 0 && (node * 2 + 1 <= tree_size && tree[node * 2 + 1] >= k))
		return ret = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int h = (int)ceil(log2(MAX_CANDY));
	tree_size = (1 << (1 + h));
	cout <<"HH"<< h;
	vector<ll> tree(tree_size);
	cin >> N;
	while (N--){
		int num;
		cin >> num;
		if (num == 1) {
			cin >> K;
			int getIndex = query(tree, 1, 0, MAX_CANDY - 1, K);
			ret = 0;
			update(tree, 1, 0, MAX_CANDY - 1, getIndex, -1);
		}
		else if (num == 2) {
			int index;
			ll val;
			cin >> index >> val;
			update(tree, 1, 0, MAX_CANDY - 1, index, val);
		}
	}
	return 0;
}