#include <string>
#include <vector>
#include<algorithm>
using namespace std;

/*
A �� B���� ��� A���� ����ǥ�� ���� B�� ������ ������ ���� -> �ִ��� ���� �̱�� ��� ���� ���
������� �ѹ��� ���� ����
����츦 ���ϸ� �ð��ʰ� ���Ű���
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