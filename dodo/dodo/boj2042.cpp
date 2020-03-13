#include<iostream>
#include<vector>
using namespace std;
/*
펜윅트리 ‘수시로 바뀌는 수열의 구간 합’을 빠르게 구할 수 있도록 고안된 자료 구조이다.
시간복잡도 O(MlonN)
구간 합 O(logN)
값 업데이트 O(logN)
공간복잡도 O(N)
A~B 까지의 구간합을 구하려면 
B의 구간합과 A-1의 구간합을 뺀다.

만약 A가 7이면 이진수로 111이다.7의 구간합은 111 + 110+ 100의 구간합을 더해준다 마지막 1의자리를  빼가면서 그 수의 구간합을 더한다.

*/
int N, M, K;
long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i>0){
		ans += tree[i];
		//1인 비트 중 끝자리를 빼가면서 구간합을 찾아간다.
		i -= (i&-i);
	}
	return ans;
}
void update(vector<long long> &tree, int i, long long diff) {
	while (i<tree.size()){
		tree[i] += diff;
		//변경 되는 수의 구간에 대해서 값을 변경해 주어야한다.
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