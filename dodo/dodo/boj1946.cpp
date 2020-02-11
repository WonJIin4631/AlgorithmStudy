#include<iostream>
#include<algorithm>
using namespace std;
/*
1차,2차 시험으로 인재를 선발

서류, 면접 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는  자만 선발
선발할수 있는 최대 인원수 출력

서류심사를 순위대로 정렬 후 1번째 있는 사원의 면접점수를 비교 만약 등수가 높으면 인원추가하며 면접점수를 높은사람값으로 변경 -> 끝까지비교

*/
int N,T;
int ans;
pair<int, int> sawon[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> sawon[i].first >> sawon[i].second;
		}
		sort(sawon, sawon + N);
		ans = 1;
		int val = sawon[0].second;
		for (int i = 1; i < N; i++) {
			if (sawon[i].second < val) {
				val = sawon[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}