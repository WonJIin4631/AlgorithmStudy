#include<iostream>
#include<vector>
using namespace std;
/*
����Ʈ�� �����÷� �ٲ�� ������ ���� �ա��� ������ ���� �� �ֵ��� ��ȵ� �ڷ� �����̴�.
�ð����⵵ O(MlonN)
���� �� O(logN)
�� ������Ʈ O(logN)
�������⵵ O(N)
A~B ������ �������� ���Ϸ��� 
B�� �����հ� A-1�� �������� ����.

���� A�� 7�̸� �������� 111�̴�.7�� �������� 111 + 110+ 100�� �������� �����ش� ������ 1���ڸ���  �����鼭 �� ���� �������� ���Ѵ�.

*/
int N, M, K;
long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i>0){
		ans += tree[i];
		//1�� ��Ʈ �� ���ڸ��� �����鼭 �������� ã�ư���.
		i -= (i&-i);
	}
	return ans;
}
void update(vector<long long> &tree, int i, long long diff) {
	while (i<tree.size()){
		tree[i] += diff;
		//���� �Ǵ� ���� ������ ���ؼ� ���� ������ �־���Ѵ�.
		i += (i&-i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	vector<long long> list(N + 1);
	vector<long long> tree(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		update(tree, i, list[i]);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			long long c;
			cin >> c;
			long long diff = c - list[b];
			list[b] = c;
			update(tree, b, diff);
		}
		else {
			int c;
			cin >> c;
			cout << sum(tree, c) - sum(tree, b - 1) << '\n';
		}
	}
	return 0;
}