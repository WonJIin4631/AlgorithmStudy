#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	string num;
	string baseNum;
	int s, b;
	for (int i = 123; i <= 987; i++) {
		num = to_string(i);
		if (num[0] == '0' || num[1] == '0' || num[2] == '0')
			continue;
		if (num[0] == num[1] || num[1] == num[2] || num[2] == num[0])
			continue;

		for (int j = 0; j <baseball.size(); j++) {
			s = 0; b = 0;
			baseNum = to_string(baseball[j][0]);
			if (baseNum[0] == num[0])
				s++;
			if (baseNum[1] == num[1])
				s++;
			if (baseNum[2] == num[2])
				s++;
			if (s != baseball[j][1])
				break;

			if (baseNum[0] == num[1] || baseNum[0] == num[2])
				b++;
			if (baseNum[1] == num[2] || baseNum[1] == num[0])
				b++;
			if (baseNum[2] == num[0] || baseNum[2] == num[1])
				b++;
			if (b != baseball[j][2])
				break;

			if (j == baseball.size() - 1) {
				answer++;
			}
		}
	}
	return answer;
}