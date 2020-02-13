#include <string>
#include <vector>
#include<algorithm>
using namespace std;

/*
A 와 B팀이 경기 A팀의 대진표는 나옴 B의 팀원의 순서를 정함 -> 최대한 많이 이기는 경기 수를 출력
각사원은 한번만 출전 가능
모든경우를 구하면 시간초과 날거같음
*/
int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int aIdx = 0;
	int bIdx = 0;
	while (true){
		if (bIdx >= B.size())
			break;
		if (A[aIdx] < B[bIdx]) {
			aIdx++;
			bIdx++;
			answer++;
		}
		else {
			bIdx++ ;
		}
	}
	return answer;
}