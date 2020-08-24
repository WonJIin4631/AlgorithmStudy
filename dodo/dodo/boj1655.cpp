#include<iostream>
#include<queue>
#include<functional>
#include<cstdio>
using namespace std;

int N;
priority_queue<int,vector<int>,greater<int>> pqMin;
priority_queue<int, vector<int>, less<int>>  pqMax;
int main() {
	scanf("%d", &N);
	int num;
	int temp;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		if (pqMax.size() == 0)
			pqMax.push(num);
		else {
			if (pqMax.size() > pqMin.size())
				pqMin.push(num);
			else
				pqMax.push(num);
			if (pqMax.top() > pqMin.top()) {
				int maxtemp = pqMax.top();
				int mintemp = pqMin.top();
				pqMax.pop();
				pqMin.pop();
				pqMax.push(mintemp);
				pqMin.push(maxtemp);
			}
		}
		printf("%d\n", pqMax.top());
	}
	return 0;
}