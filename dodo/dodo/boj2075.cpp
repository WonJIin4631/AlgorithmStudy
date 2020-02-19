#include<iostream>
#include<queue>
using namespace std;

/*
merge sort 시간복잡도 O(nlogn)
n이 1500*1500
14292410라서 가능-> 메모리제한 10Mb이라서 안됨(int 변수 32비트 4바이트)
힙을 사용해서 해결
*/
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	priority_queue<int> pq;
	for (int i = 0; i < N*N; i++) {
		//숫자 입력
		int num;
		cin >> num;
		//우선순위 큐에 N개이하있으면 넣기
		if (pq.size() < N)
			//우선순위큐 정렬 조건을 안정해서 오름차순임 -> 부호를 바꾸어서 큰값이 제일 작은값으로 유지
			pq.push(num*-1);
		//N초과인 경우
		else {
			//들어올 값과 비교 만약 큰수이면 제일 작은값 빼기
			if (pq.top()*-1 < num) {
				pq.pop();
				pq.push(num*-1);
			}
			else
				continue;
		}
	}
	cout << pq.top()*-1 << '\n';
	return 0;
}