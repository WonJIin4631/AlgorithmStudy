#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
/*
세윤은 N개과제 수행
과제는 D일밤에 제출 정확히 T일걸림
0일 부터 X까지 휴식 X+1부터 과제 시작
X 최대값 구하기


N 입력
T, D 입력
*/
typedef pair<int, int> pii;
struct info
{
	int T;
	int D;
};

info arr[1000002];
bool comp(info a, info b) {
	return a.D > b.D;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<pii> v;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int T, D;
			cin >> T >> D;
			arr[i].T = T;
			arr[i].D = D;
		}
		sort(arr, arr + N, comp);
		int endDay = arr[0].D;

		for (int i = 1; i < N; i++) {
			if (endDay - arr[i - 1].T > arr[i].D) {
				endDay = arr[i].D;
			}
			else {
				endDay = endDay - arr[i - 1].T;
			}
		}
		int ans = endDay - arr[N - 1].T;
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}