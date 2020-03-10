#include<iostream>
#include<queue>
using namespace std;
/*
�����̴� �Ȱų� �����̵��� �Ҽ� �ִ�, 1���� x-1,x+1�� �̵� �����̵� �ϴ� ��쿡�� 2*X ��ġ�� �̵�
�����̸� ������ ���� ���� �ð��� �� ������ ���ϱ�
��ġ���� �ð��� ������ �迭�� ����
������ ���� �ڸ����� �����̵� �Ҽ� �ִ� ��ġ�� �ٹ湮�Ѵ�.�����̵����Ҷ� ���� �ð��� ���ڸ��� �ð��� ���ؾߵ�
�����̵� ������ ��,�ڷ� �̵� �̵��Ҷ��� �ð��� ���ϰ� �ٽ� �����̵� �ݺ��ؼ� ����
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
