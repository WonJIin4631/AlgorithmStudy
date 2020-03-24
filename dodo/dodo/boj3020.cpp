#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
동굴의 깊이는 N 미터 높이는 H이다.
짝수는 위에서부터(종유석) 홀수는 아래서 부터(석순)
개똥벌래는 정해진 구간을 일직선으로 이동하면서 장애물을 모두 파괴

종유석 높이 1~ 최대까지 이분탐색
종유석 개수보다 석순이 많으면 높이 줄이기
반대면 높이 높이기

석순의 높이,종유석 높이 0~최대 높이까지 개수를 배열에 저장
1~H까지의 석순,종유석 개수를 더하기
1~H 까지의 총 개수가 적은 것을 저장하고 같은 수이면 anscnt값 증가
*/
int N, H;
int seok[500001] = { 0 };
int jong[500001] = { 0 };
int hList[5000001];
int ans = 987654321;
int anscnt = 0;
int main() {
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		int u, d;
		cin >> u >> d;
		seok[d]++;
		jong[u]++;
	}
	for (int i = H-1; i >=1; i--)
		seok[i] += seok[i + 1];
	for (int i = H-1; i >=1; i--)
		jong[i] += jong[i + 1];
	for (int i = 1; i <= H; i++)
		hList[i] = seok[i] + jong[H - i + 1];
	sort(hList, hList + H);
	for (int i = 1; i <= H; i++) {
		if (hList[i] < ans) {
			ans = hList[i];
			anscnt = 1;
		}
		else if (hList[i] == ans)
			anscnt++;
	}
	cout << ans << ' ' << anscnt << '\n';
	return 0;
}