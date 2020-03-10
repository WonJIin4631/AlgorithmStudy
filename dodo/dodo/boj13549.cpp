#include<iostream>
#include<queue>
using namespace std;
/*
수빈이는 걷거나 순간이동을 할수 있다, 1초후 x-1,x+1로 이동 순간이동 하는 경우에는 2*X 위치로 이동
수빈이를 만나는 가장 빠른 시간이 몇 초인지 구하기
위치별로 시간을 저장할 배열을 선언
수빈이 현재 자리에서 순간이동 할수 있는 위치를 다방문한다.순간이동을할때 지금 시간과 그자리의 시간을 비교해야됨
순간이동 끝난뒤 앞,뒤로 이동 이동할때도 시간을 비교하고 다시 순간이동 반복해서 연산
*/
int N, K;
int timeList[100002];	
typedef pair<int, int> pii;
int main() {
	cin >> N >> K;
	for (int i = 0;i <= 100000; i++) {
		timeList[i] = 987654321;
	}
	queue<pii> q;
	q.push(pii(N, 0));
	while (!q.empty()){
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		if (timeList[cur] < time)
			continue;
		timeList[cur] = time;
		int mul = 2;
		while (true){
			if (cur*mul>100000)
				break;
			if (timeList[cur*mul] > time) {
				timeList[cur*mul] = time;
				q.push(pii(cur*mul, time));
			}
			else
				break;
			mul *= 2;
		}
		if ( cur + 1 <= 100000)
			q.push(pii(cur + 1, time + 1));
		if (cur - 1 >= 0)
			q.push(pii(cur - 1, time + 1));
	}
	cout << timeList[K] << '\n';
	return 0;
}
