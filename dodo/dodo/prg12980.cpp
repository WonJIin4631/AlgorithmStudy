#include <iostream>
#include<math.h>
#include<unordered_set>
#include<queue>
using namespace std;
/*
이동방법 점프, 현재까지 온 거리 x 2로 순간이동
순간이동은 배터리소모 없음
점프는 이동한 칸 수 만큼 배터리를 소모
건전지 사용량 최소값을 반환

우선순위 큐를 사용하여 건전지 사용량이 적은 항목부터 탐색하기
-> 효율성 시간초과 발생 조건을 더 세밀하게-> 시간초과

현재 거리에서 2로 나눈 나머지 칸이 움직여야만 현재 위치의 값이나옴
나머지가 0이면 순간이동으로 움직인거

*/
int solution(int n) {
	int ans = 0;
	while (n>0) {
		ans += n % 2;
		n /= 2;
	}
	return ;
}