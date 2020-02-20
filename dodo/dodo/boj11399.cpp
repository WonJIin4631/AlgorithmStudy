#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> v;
/*
각사람이 돈을 인출하는데 필요한 시간의합이 최소로 되는것을 출력
시간을 기준 오름차순으로 정렬
맨첫번째 시간은 N번 중복 더함 2번째는 N-1번 .... 

T번째 시간은 N-T+1번 중복 되는것을 확인할 수 있음

*/
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += v[i]*(N - i);
	}
	cout << ans << '\n';
	return 0;
}