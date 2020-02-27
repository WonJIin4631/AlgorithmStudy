#include <string>
#include <vector>
#include<iostream>
using namespace std;

int answer = 0;
bool row[14] = { false };
bool toright[26] = { false };
bool toleft[26] = { false };

void DFS(int num, int n) {
	if (num > n) {
		answer++;
		return;
	}
	cout << n << '\n';
	for (int i = 1; i <= n; i++) {
		if (!row[i] && !toright[num + i] && !toleft[n + (num - i) + 1]) {
			row[i] = toright[num + i] = toleft[n + (num - i) + 1] = true;
			DFS(num + 1, n);
			row[i] = toright[num + i] = toleft[n + (num - i) + 1] = false;
		}
	}
}
int solution(int n) {

	DFS(1, n);
	return answer;
}