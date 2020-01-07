#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	answer.push_back(0);
	int cnt = 1;
	while (true){
		if (cnt == n)
			break;
		int size = answer.size();
		answer.push_back(0);
		for (int i = size-1; i >= 0; i--) {
			if (answer[i] == 0)
				answer.push_back(1);
			else
				answer.push_back(0);
		}
		cnt++;
	}

	return answer;
}