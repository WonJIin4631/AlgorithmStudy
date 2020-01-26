#include <string>
#include <vector>
#include<iostream>
using namespace std;
int cnt = 0;
vector<int> cpy;
int tar;
void DFS(int idx, int sum) {
	if (idx == cpy.size()) {
		if (sum == tar) {
			cnt++;
		}
		return;
	}
	DFS(idx + 1, sum + cpy[idx]);
	DFS(idx + 1, sum + cpy[idx] * -1);
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	cpy = numbers;
	cout << cpy.size();
	tar = target;
	answer = cnt;
	return answer;
}